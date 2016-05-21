<?php

namespace Xpl;


class HtmlElement implements \Serializable
{
    /**
     * @var string
     */
    private $_tag;

    /**
     * @var string
     */
    private $_prependString;

    /**
     * @var string
     */
    private $_appendString;

    /**
     * @var array
     */
    protected $_attributes = array();

    /**
     * @var string
     */
    protected $_content;


    /**
     * Constructor.
     */
    public function __construct() {}

    /**
     * Sets the element's HTML tag.
     *
     * @param string $tag 
     * @return \Xpl\HtmlElement 
     */
    public function setTag($tag) {}

    /**
     * Returns the element's HTML tag.
     *
     * @return string 
     */
    public function getTag() {}

    /**
     * Sets a single attribute.
     *
     * @param string $name 
     * @param mixed $value 
     * @param boolean $overwrite [Optional] Default = true
     * @return \Xpl\HtmlElement 
     */
    public function setAttribute($name, $value, $overwrite = true) {}

    /**
     * Sets the element's attributes.
     *
     * @param array $attributes 
     * @return \Xpl\HtmlElement 
     */
    public function setAttributes($attributes) {}

    /**
     * Adds an attribute to the element.
     *
     * @param string $name 
     * @param mixed $value 
     * @return \Xpl\HtmlElement 
     */
    public function addAttribute($name, $value) {}

    /**
     * Adds multiple attributes to the element.
     *
     * @param array $attributes 
     * @param array  
     * @return \Xpl\HtmlElement 
     */
    public function addAttributes($attributes) {}

    /**
     * Returns an attribute by name.
     *
     * @param string $name 
     * @return array|null 
     */
    public function getAttribute($name) {}

    /**
     * Returns the element's attributes.
     *
     * @return array 
     */
    public function getAttributes() {}

    /**
     * Checks whether the element has a given attribute.
     *
     * @param string $name 
     * @param mixed $value [Optional]
     * @return \Xpl\HtmlElement 
     */
    public function hasAttribute($name, $value = null) {}

    /**
     * Removes an attribute from the element.
     *
     * @param string $name 
     * @param mixed $value [Optional]
     * @return \Xpl\HtmlElement 
     */
    public function removeAttribute($name, $value = null) {}

    /**
     * Sets the content.
     *
     * @param string $content 
     * @return \Xpl\HtmlElement 
     */
    public function setContent($content) {}

    /**
     * Returns the content.
     *
     * @return string 
     */
    public function getContent() {}

    /**
     * Prepends content.
     *
     * @param string $content 
     * @return \Xpl\HtmlElement 
     */
    public function prependContent($content) {}

    /**
     * Appends content.
     *
     * @param string $content 
     * @return \Xpl\HtmlElement 
     */
    public function appendContent($content) {}

    /**
     * Returns the element as a string.
     *
     * @return string 
     */
    public function __toString() {}

    /**
     * @param string $content 
     * @return HtmlElement 
     */
    public function setPrependString($content) {}

    /**
     * @return string 
     */
    public function getPrependString() {}

    /**
     * @param string $content 
     * @return HtmlElement 
     */
    public function setAppendString($content) {}

    /**
     * @return string 
     */
    public function getAppendString() {}

    /**
     * @param string $content 
     * @return HtmlElement 
     */
    public function prepend($content) {}

    /**
     * @param string $content 
     * @return HtmlElement 
     */
    public function append($content) {}

    /**
     * @param string $content 
     * @return HtmlElement 
     */
    public function prependElement($content) {}

    /**
     * @param string $content 
     * @return HtmlElement 
     */
    public function appendElement($content) {}

    /**
     * @return string 
     */
    public function serialize() {}

    /**
     * @param string $serial 
     */
    public function unserialize($serial) {}

    /**
     * Returns the default attributes for the element.
     * Subclasses can overwrite this method to implement element-specific defaults.
     *
     * @return array 
     */
    protected function getDefaultAttributes() {}

    /**
     * Called at start of __toString() before any HTML is generated.
     * In subclasses, this method can be used to print sub-elements
     * in the current element's content.
     */
    protected function prepare() {}

}
