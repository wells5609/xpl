namespace Xpl\Event;

class Listener
{

	/**
	 * Event's unique identifier.
	 *
	 * @var string
	 */
	protected event_id;

	/**
	 * Callback.
	 *
	 * @var callable
	 */
	protected callback;

	/**
	 * Priority.
	 *
	 * @var integer
	 */
	protected priority;

	/**
	 * Construct listener using event ID, callback, and priority.
	 *
	 * @param string eventID Unique identifier for the event.
	 * @param callable callback Callback to run when listener called.
	 * @param integer priority Listener execution priority.
	 */
	public function __construct(string event_id, var callback, int priority) -> void
    {
		let this->event_id = event_id;
		let this->callback = callback;
		let this->priority = priority;
	}

	/**
	 * Invokes the listener's callback function.
	 *
	 * @param array args Array of arguments to pass to callback.
	 * @return mixed Result of callback.
	 */
	public function __invoke(array args)
    {
        var callback;
        let callback = this->callback;

        switch count(args) {
			// there is always at least 1 argument (the event)
			case 1:
				return {callback}(args[0]);
			case 2:
				return {callback}(args[0], args[1]);
			case 3:
				return {callback}(args[0], args[1], args[2]);
			case 4:
				return {callback}(args[0], args[1], args[2], args[3]);
			default:
				return call_user_func_array(callback, args);
		}
	}

	public function __get(var key) {
		return property_exists(this, key) ? this->{key} : null;
	}

}
