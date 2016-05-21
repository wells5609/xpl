<?php

namespace Xpl\Event;

/**
 * Event manager/container/emitter.
 * Class for binding and triggering events.
 */
class Manager
{
    /**
     * Sort and execute listeners from low-to-high priority.
     * e.g. 1 before 2, 2 before 3, etc.
     *
     * @var integer
     */
    const SORT_LOW_HIGH = 0;

    /**
     * Sort and execute listeners from high-to-low priority.
     * e.g. 3 before 2, 2 before 1, etc.
     *
     * @var integer
     */
    const SORT_HIGH_LOW = 1;

    /**
     * Sort order to use for listener priorities.
     * One of the SORT_* class constants. Default is low-to-high.
     *
     * @var integer
     */
    protected $sortOrder;

    /**
     * The sort function to use.
     *
     * @var string
     */
    protected $sortFunction;

    /**
     * Associative array of events and their listeners.
     * Event name/IDs are used as keys.
     *
     * @var array
     */
    protected $listeners;

    /**
     * Completed event objects and their results.
     *
     * @var array
     */
    protected $completed;


    /**
     * Constructor. Sets the default sort order (low to high).
     *
     * @return void 
     */
    public function __construct() {}

    /**
     * Adds an event listener.
     *
     * @param string $event Event ID.
     * @param callable $call Callable to execute on event trigger.
     * @param integer $priority [Optional] Priority to give to the listener. Default = 10
     * @return \Xpl\Event\Manager 
     */
    public function on($event, $call, $priority = 10) {}

    /**
     * Unregisters one or all listeners for an event.
     *
     * @param callable callback [Optional] Callback to remove. If no callback is given,
     * then all of the event's listeners are removed.
     * @throws \InvalidArgumentException if event is not a string or Event instance.
     * @param string|\Xpl\Event\Event $event Event ID or object.
     * @param mixed $callback 
     * @return \Xpl\Event\Manager 
     */
    public function off($event, $callback = null) {}

    /**
     * Adds an event listener which will be the only one called for the event.
     *
     * @param string $event Event ID.
     * @param callable $call Callable to execute on event trigger.
     * @return \Xpl\Event\Manager 
     */
    public function one($event, $call) {}

    /**
     * Triggers an event.
     *
     * @param \Xpl\Event\Event|string $event Event object or ID.
     * @param ... $Arguments to pass to callback.
     * @return array returned from event listeners.
     */
    public function trigger($event) {}

    /**
     * Triggers an event with an array of arguments.
     *
     * @param \Xpl\Event\Event|string $event Event object or ID.
     * @param array $args Args to pass to listeners.
     * @return array returned from event Listeners.
     */
    public function triggerArray($event, $args = array()) {}

    /**
     * Triggers a "filter" event, which returns the final event value.
     *
     * @param string|\Xpl\Event\Event $event 
     * @param mixed $value 
     * @param ... $Arguments 
     * @return mixed 
     */
    public function filter($event, $value) {}

    /**
     * Triggers a "filter" event, which returns the final event value.
     *
     * @param string|\Xpl\Event\Event $event 
     * @param array $args 
     * @return mixed 
     */
    public function filterArray($event, $args) {}

    /**
     * Returns whether an event has been completed.
     *
     * @param string $eventId Event ID.
     * @return boolean if event has completed, otherwise false.
     */
    public function did($eventId) {}

    /**
     * Returns a completed Event object.
     *
     * @param string $eventId The event's ID.
     * @return \Xpl\Event\Event completed Event object.
     */
    public function event($eventId) {}

    /**
     * Returns the array that was returned from a completed event trigger.
     * This allows you to access previously returned values (obviously).
     *
     * @param string $eventId The event's ID
     * @return array returned from the event's listeners, else null.
     */
    public function result($eventId) {}

    /**
     * Sets the listener priority sort order.
     * Tip: you can also use PHP's SORT_ASC and SORT_DESC
     *
     * @throws \DomainException if order is not one of the class constants.
     * @param int $order One of self::LOW_TO_HIGH or self::HIGH_TO_LOW
     * @return \Xpl\Event\Manager 
     */
    public function setSortOrder($order) {}

    /**
     * Returns true if sort order is low to high.
     *
     * @return boolean if sort order is low-to-high, otherwise false.
     */
    public function isLowToHigh() {}

    /**
     * Returns true if sort order is high to low.
     *
     * @return boolean if sort order is high-to-low, otherwise false.
     */
    public function isHighToLow() {}

    /**
     * Prepares event for execution by lazy-loading listener objects.
     *
     * @return boolean|array False if no listeners, otherwise indexed array of the
     * Event object (at index 0) and an array of listeners (at index 1).
     * @throws \InvalidArgumentException if event is not a string or Event object.
     * @param string|\Xpl\Event\Event $event The event ID or object to trigger.
     * @return array|bool 
     */
    protected function prepare($event) {}

    /**
     * Executes the event listeners; sorts, calls, and returns result.
     *
     * @param \Xpl\Event\Event $event Event object.
     * @param array $listeners Array of Listener objects.
     * @param array $args Callback arguments.
     * @return array of event callback results.
     */
    protected function execute(Event $event, $listeners, $args = array()) {}

    /**
     * Ascending listener sort callback.
     *
     * @param \Xpl\Event\Listener $a 
     * @param \Xpl\Event\Listener $b 
     * @return int result
     */
    public function sortListenersAsc(Listener $a, Listener $b) {}

    /**
     * Descending listener sort callback.
     *
     * @param \Xpl\Event\Listener $a 
     * @param \Xpl\Event\Listener $b 
     * @return int result
     */
    public function sortListenersDesc(Listener $a, Listener $b) {}

}
