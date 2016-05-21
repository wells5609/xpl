namespace Xpl\Event;

use InvalidArgumentException;
use DomainException;

/**
 * Event manager/container/emitter.
 *
 * Class for binding and triggering events.
 */
class Manager
{

	/**
	 * Sort and execute listeners from low-to-high priority.
	 *
	 * e.g. 1 before 2, 2 before 3, etc.
	 *
	 * @var integer
	 */
	const SORT_LOW_HIGH = 0;

	/**
	 * Sort and execute listeners from high-to-low priority.
	 *
	 * e.g. 3 before 2, 2 before 1, etc.
	 *
	 * @var integer
	 */
	const SORT_HIGH_LOW = 1;

	/**
	 * Sort order to use for listener priorities.
	 *
	 * One of the SORT_* class constants. Default is low-to-high.
	 *
	 * @var integer
	 */
	protected sortOrder;

	/**
	 * The sort function to use.
	 *
	 * @var string
	 */
	protected sortFunction;

	/**
	 * Associative array of events and their listeners.
	 *
	 * Event name/IDs are used as keys.
	 *
	 * @var array
	 */
	protected listeners;

	/**
	 * Completed event objects and their results.
	 *
	 * @var array
	 */
	protected completed;

	/**
	 * Constructor. Sets the default sort order (low to high).
	 *
	 * @return void
	 */
	public function __construct()
    {
		let this->listeners = [];
		let this->completed = [];
		this->setSortOrder(0);
	}

	/**
	 * Adds an event listener.
	 *
	 * @param string event Event ID.
	 * @param callable call Callable to execute on event trigger.
	 * @param integer priority [Optional] Priority to give to the listener. Default = 10
	 * @return \Xpl\Event\Manager
	 */
	public function on(var event, var call, int priority = 10) -> <Manager>
    {
        var listeners;

		if !fetch listeners, this->listeners[event] {
			let listeners = [];
		}

		let listeners[] = new Listener(event, call, priority);

        let this->listeners[event] = listeners;

		return this;
	}

	/**
	 * Unregisters one or all listeners for an event.
	 *
	 * @param string|\Xpl\Event\Event event Event ID or object.
	 * @param callable callback [Optional] Callback to remove. If no callback is given,
	 * then all of the event's listeners are removed.
	 * @return \Xpl\Event\Manager
	 *
	 * @throws \InvalidArgumentException if event is not a string or Event instance.
	 */
	public function off(var event, var callback = null) -> <Manager>
    {
        var id, listeners;

		if typeof event == "string" {
			let id = event;
		} elseif (event instanceof Event) {
			let id = event->id;
		} else {
			throw new InvalidArgumentException("Event must be string or instance of Event, given: " . gettype(event));
		}

		if fetch listeners, this->listeners[id] {

			if typeof callback == "null" {
                // if no callback given, unset all listeners
    			unset listeners[id];

            } else {
                var i, listener;

				// iterate through listeners and unset matching callback
				for i, listener in listeners {

                    if callback == listener->callback {
						unset listeners[i];
					}
				}
			}

            let this->listeners[id] = listeners;
		}

		return this;
	}

	/**
	 * Adds an event listener which will be the only one called for the event.
	 *
	 * @param string event Event ID.
	 * @param callable call Callable to execute on event trigger.
	 * @return \Xpl\Event\Manager
	 */
	public function one(var event, var call) -> <Manager>
    {
		if ! isset this->listeners[event] {
			let this->listeners[event] = [];
		}

		let this->listeners[event]["one"] = new Listener(event, call, 1);

		return this;
	}

	/**
	 * Triggers an event.
	 *
	 * @param \Xpl\Event\Event|string event Event object or ID.
	 * @param ... Arguments to pass to callback.
	 * @return array Items returned from event listeners.
	 */
	public function trigger(var event)
    {
        var prepared, eventObj, listeners, args;

        // prepare the event
		let prepared = this->prepare(event);

		if prepared === false {
			return [];
		}

        let eventObj = prepared[0];
        let listeners = prepared[1];

		//list(event, listeners) = prepared;

		// get function args
		let args = func_get_args();

		// remove event from args
		array_shift(args);

		return this->execute(eventObj, listeners, args);
	}

	/**
	 * Triggers an event with an array of arguments.
	 *
	 * @param \Xpl\Event\Event|string event Event object or ID.
	 * @param array args Args to pass to listeners.
	 * @return array Items returned from event Listeners.
	 */
	public function triggerArray(var event, array args = [])
    {
        var prepared, eventObj, listeners;

        // prepare the event
        let prepared = this->prepare(event);

        if prepared === false {
            return [];
        }

        let eventObj = prepared[0];
        let listeners = prepared[1];

		return this->execute(eventObj, listeners, args);
	}

	/**
	 * Triggers a "filter" event, which returns the final event value.
	 *
	 * @param string|\Xpl\Event\Event event
	 * @param mixed value
	 * @param ... Arguments
	 * @return mixed
	 */
	public function filter(var event, var value)
    {
        var args;

		// get function args
		let args = func_get_args();

		// remove event from args
		array_shift(args);

		return this->filterArray(event, args);
	}

	/**
	 * Triggers a "filter" event, which returns the final event value.
	 *
	 * @param string|\Xpl\Event\Event event
	 * @param array args
	 * @return mixed
	 */
	public function filterArray(var event, array args)
    {
        var prepared, eventObj, listeners;

        // prepare the event
        let prepared = this->prepare(event);

        if prepared === false {
            // No listeners, return the initial value
			return reset(args);
        }

        let eventObj = prepared[0];
        let listeners = prepared[1];

		let eventObj->value = array_shift(args);

		this->execute(eventObj, listeners, args);

		return eventObj->value;
	}

	/**
	 * Returns whether an event has been completed.
	 *
	 * @param string eventId Event ID.
	 * @return boolean True if event has completed, otherwise false.
	 */
	public function did(string eventId) -> boolean
    {
		return isset this->completed[eventId];
	}

	/**
	 * Returns a completed Event object.
	 *
	 * @param string eventId The event's ID.
	 * @return \Xpl\Event\Event The completed Event object.
	 */
	public function event(string eventId) -> <Event>|null
    {
		return isset this->completed[eventId] ? this->completed[eventId]["event"] : null;
	}

	/**
	 * Returns the array that was returned from a completed event trigger.
	 *
	 * This allows you to access previously returned values (obviously).
	 *
	 * @param string eventId The event's ID
	 * @return array Values returned from the event's listeners, else null.
	 */
	public function result(string eventId) -> array|null
    {
		return isset this->completed[eventId] ? this->completed[eventId]["result"] : null;
	}

	/**
	 * Sets the listener priority sort order.
	 *
	 * Tip: you can also use PHP's SORT_ASC and SORT_DESC
	 *
	 * @param int order One of self::LOW_TO_HIGH or self::HIGH_TO_LOW
	 * @return \Xpl\Event\Manager
	 *
	 * @throws \DomainException if order is not one of the class constants.
	 */
	public function setSortOrder(int order) -> <Manager>
    {
		if (order != 0 && order != 1) {
			throw new DomainException("Invalid sort order.");
		}

		let this->sortOrder = order;

		let this->sortFunction = "sortListeners" . (this->sortOrder === 0 ? "Asc" : "Desc");

		return this;
	}

	/**
	 * Returns true if sort order is low to high.
	 *
	 * @return boolean True if sort order is low-to-high, otherwise false.
	 */
	public function isLowToHigh() -> boolean
    {
		return this->sortOrder === Manager::SORT_LOW_HIGH;
	}

	/**
	 * Returns true if sort order is high to low.
	 *
	 * @return boolean True if sort order is high-to-low, otherwise false.
	 */
	public function isHighToLow() -> boolean
    {
		return this->sortOrder === Manager::SORT_HIGH_LOW;
	}

	/**
	 * Prepares event for execution by lazy-loading listener objects.
	 *
	 * @param string|\Xpl\Event\Event event The event ID or object to trigger.
	 * @return boolean|array False if no listeners, otherwise indexed array of the
	 * Event object (at index 0) and an array of listeners (at index 1).
	 *
	 * @throws \InvalidArgumentException if event is not a string or Event object.
	 */
	protected function prepare(var event) -> array|boolean
    {
        var eventObj, eventId, listeners, onceListener;

        if typeof event == "string" {
            let eventId = event;
			let eventObj = new Event(event);
		} elseif (event instanceof Event) {
            let eventObj = event;
            let eventId = event->getID();
        } else {
            throw new InvalidArgumentException("Event must be string or instance of Event, given: " . gettype(event));
        }

		// check if have listeners
		if !fetch listeners, this->listeners[eventId] {
            return false;
        }

		// Check if a "one" listener exists - if it does, call no others.
        if fetch onceListener, listeners["one"] {
            return [eventObj, [onceListener]];
        }

		return [eventObj, listeners];
	}

	/**
	 * Executes the event listeners; sorts, calls, and returns result.
	 *
	 * @param \Xpl\Event\Event event Event object.
	 * @param array listeners Array of Listener objects.
	 * @param array args Callback arguments.
	 * @return array Array of event callback results.
	 */
	protected function execute(<Event> event, array! listeners, array! args = []) -> array
    {
        var results, listener, value;

		let results = [];

		// Sort listeners by priority
		usort(listeners, [this, this->sortFunction]);

		// Prepend event to args array
		array_unshift(args, event);

		// Call each listener
		for listener in listeners {

			// Collect the returned value
			let value = {listener}(args);
            let results[] = value;

			// Update the event value
			if value !== null {
                if value !== event->value {
                    let event->value = value;
                }
            }

			//unset value;
            let value = null;

			// End if propagation stopped
			if event->isPropagationStopped() {
				break;
			}
		}

		// Save the event object and result array
		let this->completed[event->getID()] = [
			"event": event,
			"result": results
		];

		// Return the array of results
		return results;
	}

	/**
	 * Ascending listener sort callback.
	 *
	 * @param \Xpl\Event\Listener a
	 * @param \Xpl\Event\Listener b
	 * @return int Sort result
	 */
	public function sortListenersAsc(<Listener> a, <Listener> b) -> int
    {
		return (a->priority >= b->priority) ? 1 : -1;
	}

	/**
	 * Descending listener sort callback.
	 *
	 * @param \Xpl\Event\Listener a
	 * @param \Xpl\Event\Listener b
	 * @return int Sort result
	 */
	public function sortListenersDesc(<Listener> a, <Listener> b) -> int
    {
		return (a->priority <= b->priority) ? 1 : -1;
	}

}
