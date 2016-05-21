<?php

namespace Xpl;


class Html
{
    /**
     * Whether to use HTML5
     *
     * @var boolean
     */
    static protected $html5 = true;

    /**
     * Self-closing tags.
     *
     * @var array
     */
    static protected $selfClosingTags;


    /**
     * Create an HTML element string.
     *
     * @param string $tag 
     * @param mixed $attributes 
     * @param string $content 
     * @param string $$tag Element tag.
     * @param mixed $$attributes [Optional] Element attribute array or string.
     * @param string $$content [Optional] Element content to place between opening and closing tags.
     * @return string element string.
     */
    public static function make($tag, $attributes = null, $content = "") {}

    /**
     * Creates an attribute string for an element
     *
     * @param mixed $attributes 
     * @param string|array $$attributes Attribute string or array
     * @return string string
     */
    public static function attributeString($attributes) {}

    /**
     * Parses a string of attributes to an array
     *
     * @param string|array $str Attribute string/array
     * @return array 
     */
    public static function parseAttributes($str) {}

    /**
     * Applies htmlentities() to an attribute string using ENT_NOQUOTES to protect against XSS
     *
     * @param string $str 
     * @param string $$str Attribute value string
     * @return string attribute value
     */
    public static function escapeAttribute($str) {}

    /**
     * Whether the given tag is self-closing.
     *
     * @param string $tag 
     * @param string $$tag Element tag.
     * @return boolean 
     */
    public static function isSelfClosingTag($tag) {}

}
