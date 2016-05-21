namespace Xpl\Event;

use RuntimeException;

class Event
{

	/**
	 * Unique identifier for the event.
	 *
	 * @var string
	 */
	protected id;

	/**
	 * Event value.
	 *
	 * @var mixed
	 */
	public value;

	/**
	 * Whether the default behavior should be prevented.
	 *
	 * @var boolean
	 */
	private defaultPrevented = false;

	/**
	 * Whether propagation should be stopped.
	 *
	 * @var boolean
	 */
	private propagationStopped = false;

	/**
	 * Constructor takes one string parameter, the event ID.
	 *
	 * @param string id Event identifier.
	 */
	public function __construct(string id) -> void
    {
		let this->id = id;
	}

    /**
     * Returns the event ID.
     *
     * @return string
     */
    public function getID() -> string
    {
        return this->id;
    }

	/**
	 * Prevents execution of the event"s default behavior.
	 *
	 * @return \Xpl\Event\Event
	 */
	final public function preventDefault() -> <Event>
    {
		let this->defaultPrevented = true;
		return this;
	}

	/**
	 * Stops propagation of the event.
	 *
	 * @return \Xpl\Event\Event
	 */
	final public function stopPropagation() -> <Event>
    {
		let this->propagationStopped = true;
		return this;
	}

	/**
	 * Returns true if preventDefault() has been called on the event.
	 *
	 * @return boolean
	 */
	final public function isDefaultPrevented() -> boolean
    {
		return this->defaultPrevented;
	}

	/**
	 * Returns true if stopPropagation() has been called on the event.
	 *
	 * @return boolean
	 */
	final public function isPropagationStopped() -> boolean
    {
		return this->propagationStopped;
	}

	/**
	 * Magic get to allow access to non-public properties.
	 *
	 * @param string var Propety name.
	 * @return mixed Property value or null.
	 */
	public function __get(string key)
    {
		if "preventDefault" === key {
			return this->defaultPrevented;
		} elseif "stopPropagation" === key {
			return this->propagationStopped;
		}

		return property_exists(this, key) ? this->{key} : null;
	}

	public function __isset(string key) {

		if ("preventDefault" === key || "stopPropagation" === key) {
			return true;
		}

		return property_exists(this, key);
	}

	public function __set(string key, var value) {

		if ("defaultPrevented" === key || "preventDefault" === key) {
			let this->defaultPrevented = (boolean)value;
		} elseif ("propagationStopped" === key || "stopPropagation" === key) {
			let this->propagationStopped = (boolean)value;
		} else {
			let this->{key} = value;
		}
	}

	public function __unset(key) {

		if in_array(key, ["defaultPrevented", "preventDefault", "propagationStopped", "stopPropagation"], true) {
			throw new RuntimeException("Cannot unset private properties.");
		}

		let this->{key} = null;
	}

}
