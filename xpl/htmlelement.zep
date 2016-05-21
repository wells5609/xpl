namespace Xpl;

class HtmlElement implements \Serializable
{

	/**
	 * @var string
	 */
	private _tag;

	/**
	 * @var string
	 */
	private _prependString;

	/**
	 * @var string
	 */
	private _appendString;

	/**
	 * @var array
	 */
	protected _attributes = [];

	/**
	 * @var string
	 */
	protected _content;

    /**
     * Constructor.
     */
	public function __construct()
    {
		this->setTag("div");
        this->setAttributes(this->getDefaultAttributes());
	}

    /**
     * Sets the element's HTML tag.
     *
     * @param string tag
     * @return \Xpl\HtmlElement
     */
	public function setTag(string tag) -> <HtmlElement>
    {
		let this->_tag = strtolower(tag);
		return this;
	}

    /**
     * Returns the element's HTML tag.
     *
     * @return string
     */
	public function getTag() -> string
    {
		return this->_tag;
	}

    /**
     * Sets a single attribute.
     *
     * @param string name
     * @param mixed value
     * @param boolean overwrite [Optional] Default = true
     * @return \Xpl\HtmlElement
     */
	public function setAttribute(string name, var value, boolean overwrite = true) -> <HtmlElement>
    {
        var attrs, arrVal;
        let attrs = this->_attributes;

        if typeof value == "array" {
            let arrVal = value;
        } else {
            let arrVal = [value];
        }

		if ! isset attrs[name] || overwrite {
			let attrs[name] = arrVal;
		} else {
			let attrs[name] = array_merge(attrs[name], arrVal);
		}

        let this->_attributes = attrs;

		return this;
	}

    /**
     * Sets the element's attributes.
     *
     * @param array attributes
     * @return \Xpl\HtmlElement
     */
	public function setAttributes(array attributes) -> <HtmlElement>
    {
        var name, value;

        for name, value in attributes {
			this->setAttribute(name, value);
		}

		return this;
	}

    /**
     * Adds an attribute to the element.
     *
     * @param string name
     * @param mixed value
     * @return \Xpl\HtmlElement
     */
	public function addAttribute(string name, var value) -> <HtmlElement>
    {
		return this->setAttribute(name, value, false);
	}

    /**
     * Adds multiple attributes to the element.
     *
     * @param array
     * @return \Xpl\HtmlElement
     */
	public function addAttributes(array attributes) -> <HtmlElement>
    {
        var name, value;

		for name, value in attributes {
			this->addAttribute(name, value);
		}

		return this;
	}

    /**
     * Returns an attribute by name.
     *
     * @param string name
     * @return array|null
     */
	public function getAttribute(string name) -> array|null
    {
		return isset this->_attributes[name] ? this->_attributes[name] : null;
	}

    /**
     * Returns the element's attributes.
     *
     * @return array
     */
	public function getAttributes() -> array
    {
		return this->_attributes;
	}

    /**
     * Checks whether the element has a given attribute.
     *
     * @param string name
     * @param mixed value [Optional]
     * @return \Xpl\HtmlElement
     */
	public function hasAttribute(string name, var value = null) -> boolean
    {
		if ! isset this->_attributes[name] {
			return false;
		}

        if typeof value == "null" {
            return true;
        }

		return in_array(value, this->_attributes[name], true);
	}

	/**
	 * Removes an attribute from the element.
	 *
	 * @param string name
	 * @param mixed value [Optional]
	 * @return \Xpl\HtmlElement
	 */
	public function removeAttribute(string name, var value = null) -> <HtmlElement>
	{
		var attributeValues;

		if fetch attributeValues, this->_attributes[name] {

			if typeof value == "null" {
				unset this->_attributes[name];
			} else {
				var valueKey;
				let valueKey = array_search(value, attributeValues, true);

				if valueKey !== false {
					unset attributeValues[valueKey];
					let this->_attributes[name] = attributeValues;
				}
			}
		}

		return this;
	}

    /**
     * Sets the content.
     *
     * @param string content
     * @return \Xpl\HtmlElement
     */
	public function setContent(string content) -> <HtmlElement>
    {
		let this->_content = content;
		return this;
	}

    /**
     * Returns the content.
     *
     * @return string
     */
	public function getContent() -> string
    {
		return (string)this->_content;
	}

    /**
     * Prepends content.
     *
     * @param string content
     * @return \Xpl\HtmlElement
     */
	public function prependContent(string content) -> <HtmlElement>
    {
		let this->_content = content . this->_content;
        return this;
	}

    /**
     * Appends content.
     *
     * @param string content
     * @return \Xpl\HtmlElement
     */
	public function appendContent(string content) -> <HtmlElement>
    {
		let this->_content .= content;
        return this;
	}

    /**
     * Returns the element as a string.
     *
     * @return string
     */
	public function __toString() -> string
    {
        string html = "";

		this->prepare();

        let html .= this->getPrependString();
		let html .= Html::make(this->getTag(), this->getAttributes(), this->getContent());
        let html .= this->getAppendString();

		return html;
	}

	public function setPrependString(string content) -> <HtmlElement>
    {
		let this->_prependString = content;
		return this;
	}

	public function getPrependString() -> string
    {
		return (string)this->_prependString;
	}

	public function setAppendString(string content) -> <HtmlElement>
    {
		let this->_appendString = content;
        return this;
	}

	public function getAppendString() -> string
    {
		return (string)this->_appendString;
	}

	public function prepend(string content) -> <HtmlElement>
    {
		let this->_prependString = content . this->_prependString;
        return this;
	}

	public function append(string content) -> <HtmlElement>
    {
		let this->_appendString .= content;
        return this;
	}

	public function prependElement(string content) -> <HtmlElement>
    {
		let this->_prependString .= content;
        return this;
	}

	public function appendElement(string content) -> <HtmlElement>
    {
		let this->_appendString = content . this->_appendString;
        return this;
	}

	public function serialize() -> string
	{
		return serialize(get_object_vars(this));
	}

	public function unserialize(string! serial) -> void
	{
		var key, value;
		for key, value in unserialize(serial) {
			let this->{key} = value;
		}
	}

	/**
	 * Returns the default attributes for the element.
	 *
	 * Subclasses can overwrite this method to implement element-specific defaults.
	 *
	 * @return array
	 */
	protected function getDefaultAttributes() -> array
	{
		return [];
	}

    /**
     * Called at start of __toString() before any HTML is generated.
     *
     * In subclasses, this method can be used to print sub-elements
     * in the current element's content.
     */
	protected function prepare()
    {

    }

}
