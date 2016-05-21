<?php

namespace Xpl;

/**
 * Implementation of PSR HTTP stream.
 */
class Stream implements \Psr\Http\Message\StreamInterface
{

    const READ = "r";


    const WRITE = "w";


    const READ_WRITE = "r+";


    const READ_WRITE_CREATE = "w+";


    const BINARY_READ = "rb";


    const BINARY_WRITE = "wb";


    const BINARY_READ_WRITE = "r+b";


    const BINARY_READ_WRITE_CREATE = "w+b";

    /**
     * @var resource
     */
    private $handle;

    /**
     * @var string|resource
     */
    private $stream;

    /**
     * @var boolean
     */
    private $readable = false;

    /**
     * @var boolean
     */
    private $writable = false;

    /**
     * @var boolean
     */
    private $seekable = false;


    /**
     * Creates a new temporary stream.
     *
     * @param string $mode [Optional] Default = "w+b". Must be a writable mode.
     * @param int $memoryLimitMb [Optional] Default = 2. Max memory used before temporary file.
     * @return \Xpl\Stream 
     */
    public static function temp($mode = self::BINARY_READ_WRITE_CREATE, $memoryLimitMb = 0) {}

    /**
     * @throws InvalidArgumentException
     * @param string|resource $stream 
     * @param string $mode Mode with which to open stream
     */
    public function __construct($stream, $mode = self::READ) {}

    /**
     * Reads all data from the stream into a string, from the beginning to end.
     * This method MUST attempt to seek to the beginning of the stream before
     * reading data and read the stream until the end is reached.
     * Warning: This could attempt to load a large amount of data into memory.
     * This method MUST NOT raise an exception in order to conform with PHP's
     * string casting operations.
     *
     * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
     * @return string 
     */
    public function __toString() {}

    /**
     * Closes the stream and any underlying resources.
     *
     * @return void 
     */
    public function close() {}

    /**
     * Separates any underlying resources from the stream.
     * After the stream has been detached, the stream is in an unusable state.
     *
     * @return resource|null PHP stream, if any
     */
    public function detach() {}

    /**
     * Attach a new stream/resource to the instance.
     *
     * @throws InvalidArgumentException for stream identifier that cannot be
     * cast to a resource
     * @throws InvalidArgumentException for non-resource stream
     * @param mixed $resourceHandle 
     * @param string $mode 
     * @param string|resource $resource 
     */
    public function attach($resourceHandle, $mode) {}

    /**
     * Get the size of the stream if known.
     *
     * @return int|null the size in bytes if known, or null if unknown.
     */
    public function getSize() {}

    /**
     * Returns the current position of the file read/write pointer
     *
     * @throws \RuntimeException on error.
     * @return int of the file pointer
     */
    public function tell() {}

    /**
     * Returns true if the stream is at the end of the stream.
     *
     * @return bool 
     */
    public function eof() {}

    /**
     * Returns whether or not the stream is seekable.
     *
     * @return bool 
     */
    public function isSeekable() {}

    /**
     * Seek to a position in the stream.
     *
     * @link http://www.php.net/manual/en/function.fseek.php
     * @param int whence Specifies how the cursor position will be calculated
     * based on the seek offset. Valid values are identical to the built-in
     * PHP whence values for `fseek()`.
     * SEEK_SET: (default) Set position equal to offset bytes.
     * SEEK_CUR: Set position to current location plus offset.
     * SEEK_END: Set position to end-of-stream plus offset.
     * @throws \RuntimeException on failure.
     * @param int $offset Stream offset
     * @param int $whence 
     * @return bool 
     */
    public function seek($offset, $whence = 0) {}

    /**
     * Seek to the beginning of the stream.
     * If the stream is not seekable, this method will raise an exception;
     * otherwise, it will perform a seek(0).
     *
     * @see seek()
     * @link http://www.php.net/manual/en/function.fseek.php
     * @throws \RuntimeException on failure.
     */
    public function rewind() {}

    /**
     * Returns whether or not the stream is writable.
     *
     * @return bool 
     */
    public function isWritable() {}

    /**
     * Write data to the stream.
     *
     * @throws \RuntimeException on failure.
     * @param string $str 
     * @param string $string The string that is to be written.
     * @return int the number of bytes written to the stream.
     */
    public function write($str) {}

    /**
     * Returns whether or not the stream is readable.
     *
     * @return bool 
     */
    public function isReadable() {}

    /**
     * Read data from the stream.
     *
     * @param int length Read up to length bytes from the object and return
     * them. Fewer than length bytes may be returned if underlying stream
     * call returns fewer bytes.
     * @return string Returns the data read from the stream, or an empty string
     * if no bytes are available.
     * @throws \RuntimeException if an error occurs.
     * @param int $length 
     * @return string 
     */
    public function read($length) {}

    /**
     * Returns the remaining contents in a string
     *
     * @throws \RuntimeException if unable to read or an error occurs while
     * reading.
     * @return string 
     */
    public function getContents() {}

    /**
     * Get stream metadata as an associative array or retrieve a specific key.
     * The keys returned are identical to the keys returned from PHP"s
     * stream_get_meta_data() function.
     *
     * @link http://php.net/manual/en/function.stream-get-meta-data.php
     * @return array|mixed|null Returns an associative array if no key is
     * provided. Returns a specific key value if a key is provided and the
     * value is found, or null if the key is not found.
     * @param string $key Specific metadata to retrieve.
     * @return array|mixed|null 
     */
    public function getMetadata($key = null) {}

    /**
     * Set the internal stream resource.
     *
     * @throws InvalidArgumentException for invalid streams or resources.
     * @param string|resource $stream String stream target or stream resource.
     * @param string $streamMode 
     * @param string $mode Resource mode for stream target.
     */
    private function setStream($stream, $streamMode) {}

    /**
     * Resets the object to its default state.
     */
    protected function reset() {}

}
