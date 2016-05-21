namespace Xpl;

use Psr\Http\Message\StreamInterface;
use InvalidArgumentException;
use RuntimeException;

/**
 * Implementation of PSR HTTP stream.
 */
class Stream implements StreamInterface
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
    private handle;

    /**
     * @var string|resource
     */
    private stream;

    /**
     * @var boolean
     */
    private readable = false;

    /**
     * @var boolean
     */
    private writable = false;

    /**
     * @var boolean
     */
    private seekable = false;

    /**
     * Creates a new temporary stream.
     *
     * @param string mode [Optional] Default = "w+b". Must be a writable mode.
     * @param int maxMemoryMb [Optional] Default = 2. Max memory used before temporary file.
     *
     * @return \Xpl\Stream
     */
    public static function temp(
        const string mode = self::BINARY_READ_WRITE_CREATE,
        const int maxMemoryMb = 0
    ) -> <Stream>
    {
        var filename;

    	if maxMemoryMb === 0 {
    		let filename = "php://temp";
    	} else {
    		let filename = "php://temp/maxmemory=" . (1024 * 1024 * maxMemoryMb);
    	}

    	return new self(filename, mode);
    }

    /**
     * Constructor.
     *
     * @param string|resource stream
     * @param string mode Mode with which to open stream [Optional] Default = "rb"
     *
     * @throws InvalidArgumentException
     */
    public function __construct(const var stream, const string mode = self::BINARY_READ) -> void
    {
        this->setStream(stream, mode);
    }

    /**
     * Reads all data from the stream into a string, from the beginning to end.
     *
     * This method MUST attempt to seek to the beginning of the stream before
     * reading data and read the stream until the end is reached.
     *
     * Warning: This could attempt to load a large amount of data into memory.
     *
     * This method MUST NOT raise an exception in order to conform with PHP's
     * string casting operations.
     *
     * @see http://php.net/manual/en/language.oop5.magic.php#object.tostring
     *
     * @return string
     */
    public function __toString() -> string
    {
        var e;

        if this->isReadable() {
            try {
                this->rewind();
                return this->getContents();
            } catch RuntimeException, e {
                return "";
            }
        }

        return "";
    }

    /**
     * Returns the underlying resource handle.
     *
     * @return resource|null
     */
    public function getHandle() -> var | null
    {
        return this->handle;
    }

    /**
     * Closes the stream and any underlying resources.
     *
     * @return void
     */
    public function close() -> void
    {
        var resourceHandle;

        if typeof this->handle != "null" {
            let resourceHandle = this->detach();
            fclose(resourceHandle);
        }
    }

    /**
     * Separates any underlying resources from the stream.
     *
     * After the stream has been detached, the stream is in an unusable state.
     *
     * @return resource|null Underlying PHP stream, if any
     */
    public function detach() -> var | null
    {
        var resourceHandle;
        let resourceHandle = this->handle;

        this->reset();

        return resourceHandle;
    }

    /**
     * Attach a new stream/resource to the instance.
     *
     * @param string|resource resource
     * @param string mode
     *
     * @throws InvalidArgumentException for stream identifier that cannot be
     *     cast to a resource
     * @throws InvalidArgumentException for non-resource stream
     */
    public function attach(var resourceHandle, string! mode)
    {
        this->setStream(resourceHandle, mode);
    }

    /**
     * Get the size of the stream if known.
     *
     * @return int|null Returns the size in bytes if known, or null if unknown.
     */
    public function getSize() -> int | null
    {
        var stats, size;

        if typeof this->handle != "null" {

            let stats = fstat(this->handle);

            if fetch size, stats["size"] {
                return (int)size;
            }
        }

        return null;
    }

    /**
     * Returns the current position of the file read/write pointer
     *
     * @return int Position of the file pointer
     *
     * @throws \RuntimeException on error.
     */
    public function tell() -> int
    {
        if typeof this->handle == "null" {
            throw new RuntimeException("No resource available; cannot tell position");
        }

        var result;
        let result = ftell(this->handle);

        if typeof result != "integer" {
            throw new RuntimeException("Error occurred during tell operation");
        }

        return result;
    }

    /**
     * Returns true if the stream is at the end of the stream.
     *
     * @return bool
     */
    public function eof() -> boolean
    {
        if typeof this->handle == "null" {
            return true;
        }

        return feof(this->handle);
    }

    /**
     * Returns whether or not the stream is seekable.
     *
     * @return bool
     */
    public function isSeekable() -> boolean
    {
        return this->seekable;
    }

    /**
     * Seek to a position in the stream.
     *
     * @link http://www.php.net/manual/en/function.fseek.php
     *
     * @param int offset Stream offset
     * @param int whence Specifies how the cursor position will be calculated
     *     based on the seek offset. Valid values are identical to the built-in
     *     PHP whence values for `fseek()`.
     *     SEEK_SET: (default) Set position equal to offset bytes.
     *     SEEK_CUR: Set position to current location plus offset.
     *     SEEK_END: Set position to end-of-stream plus offset.
     *
     * @return bool
     *
     * @throws \RuntimeException on failure.
     */
    public function seek(const int offset, const int whence = 0) -> boolean
    {
        if unlikely(typeof this->handle == "null") {
            throw new RuntimeException("No resource available; cannot seek position");
        }

        if ! this->seekable {
            throw new RuntimeException("Stream is not seekable");
        }

        var result;
        let result = fseek(this->handle, offset, whence);

        if result !== 0 {
            throw new RuntimeException("Error seeking within stream");
        }

        return true;
    }

    /**
     * Seek to the beginning of the stream.
     *
     * If the stream is not seekable, this method will raise an exception;
     * otherwise, it will perform a seek(0).
     *
     * @see seek()
     *
     * @link http://www.php.net/manual/en/function.fseek.php
     *
     * @throws \RuntimeException on failure.
     */
    public function rewind() -> void
    {
        this->seek(0);
    }

    /**
     * Returns whether or not the stream is writable.
     *
     * @return bool
     */
    public function isWritable() -> boolean
    {
        return this->writable;
    }

    /**
     * Write data to the stream.
     *
     * @param string string The string that is to be written.
     *
     * @return int Returns the number of bytes written to the stream.
     *
     * @throws \RuntimeException on failure.
     */
    public function write(const string str) -> int
    {
        var result;

        if unlikely(typeof this->handle == "null") {
            throw new RuntimeException("No resource available; cannot write");
        }

        if this->writable === false {
            throw new RuntimeException("Stream is not writable");
        }

        let result = fwrite(this->handle, str);

        if result === false {
            throw new RuntimeException("Error writing to stream");
        }

        return result;
    }

    /**
     * Returns whether or not the stream is readable.
     *
     * @return bool
     */
    public function isReadable() -> boolean
    {
        return this->readable;
    }

    /**
     * Read data from the stream.
     *
     * @param int length Read up to length bytes from the object and return
     *     them. Fewer than length bytes may be returned if underlying stream
     *     call returns fewer bytes.
     *
     * @return string Returns the data read from the stream, or an empty string
     *     if no bytes are available.
     *
     * @throws \RuntimeException if an error occurs.
     */
    public function read(const int length) -> string
    {
        var result;

        if unlikely(typeof this->handle == "null") {
            throw new RuntimeException("No resource available; cannot read");
        }

        if this->readable === false {
            throw new RuntimeException("Stream is not readable");
        }

        let result = fread(this->handle, length);

        if result === false {
            throw new RuntimeException("Error reading stream");
        }

        return result;
    }

    /**
     * Returns the remaining contents in a string
     *
     * @return string
     *
     * @throws \RuntimeException if unable to read or an error occurs while
     *     reading.
     */
    public function getContents() -> string
    {
        var result;

        if unlikely(typeof this->handle == "null") {
            throw new RuntimeException("No resource available; cannot get contents");
        }

        if this->readable === false {
            throw new RuntimeException("Stream is not readable");
        }

        let result = stream_get_contents(this->handle);

        if result === false {
            throw new RuntimeException("Error reading from stream");
        }

        return result;
    }

    /**
     * Get stream metadata as an associative array or retrieve a specific key.
     *
     * The keys returned are identical to the keys returned from PHP"s
     * stream_get_meta_data() function.
     *
     * @link http://php.net/manual/en/function.stream-get-meta-data.php
     *
     * @param string key Specific metadata to retrieve.
     *
     * @return array|mixed|null Returns an associative array if no key is
     *     provided. Returns a specific key value if a key is provided and the
     *     value is found, or null if the key is not found.
     */
    public function getMetadata(var key = null) -> array | var | null
    {
        var metadata, value;

        let metadata = stream_get_meta_data(this->handle);

        if typeof key == "null" {
            return metadata;
        }

        if fetch value, metadata[key] {
            return value;
        }

        return null;
    }

    /**
     * Set the internal stream resource.
     *
     * @param string|resource stream String stream target or stream resource.
     * @param string mode Resource mode for stream target.
     *
     * @throws InvalidArgumentException for invalid streams or resources.
     */
    private function setStream(const var stream, const string! streamMode) -> void
    {
        var resourceHandle, metadata, mode, isSeekable;
        boolean allowRead = false, allowWrite = false;

        if typeof stream == "string" {
            let resourceHandle = fopen(stream, streamMode);
        } else {
            let resourceHandle = stream;
        }

        if ! is_resource(resourceHandle) || get_resource_type(resourceHandle) !== "stream" {
            throw new InvalidArgumentException(
                "Invalid stream provided; must be a string stream identifier or stream resource"
            );
        }

        this->reset();

        let this->handle = resourceHandle;

        if stream !== resourceHandle {
            let this->stream = stream;
        }

        let metadata = stream_get_meta_data(resourceHandle);

        if fetch mode, metadata["mode"] {
            if memstr(mode, "+") {
                let allowRead = true;
                let allowWrite = true;
            } else {
                if memstr(mode, "r") {
                    let allowRead = true;
                }
                if memstr(mode, "w") || memstr(mode, "x") || memstr(mode, "c") || memstr(mode, "a") {
                    let allowWrite = true;
                }
            }
        }

        let this->readable = allowRead;
        let this->writable = allowWrite;

        if fetch isSeekable, metadata["seekable"] {
            let this->seekable = (bool) isSeekable;
        }
    }

    /**
     * Resets the object to its default state.
     */
    private function reset() -> void
    {
        let this->handle = null;
        let this->stream = null;
        let this->readable = false;
        let this->writable = false;
        let this->seekable = false;
    }

    /**
     * Destructor.
     *
     * Closes the resource, just for good measure.
     */
    public function __destruct() -> void
    {
        this->close();
    }

}
