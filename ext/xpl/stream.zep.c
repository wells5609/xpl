
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Implementation of PSR HTTP stream.
 */
ZEPHIR_INIT_CLASS(Xpl_Stream) {

	ZEPHIR_REGISTER_CLASS(Xpl, Stream, xpl, stream, xpl_stream_method_entry, 0);

	/**
	 * @var resource
	 */
	zend_declare_property_null(xpl_stream_ce, SL("handle"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string|resource
	 */
	zend_declare_property_null(xpl_stream_ce, SL("stream"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_stream_ce, SL("readable"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_stream_ce, SL("writable"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_stream_ce, SL("seekable"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("READ"), "r" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("WRITE"), "w" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("READ_WRITE"), "r+" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("READ_WRITE_CREATE"), "w+" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("BINARY_READ"), "rb" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("BINARY_WRITE"), "wb" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("BINARY_READ_WRITE"), "r+b" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_stream_ce, SL("BINARY_READ_WRITE_CREATE"), "w+b" TSRMLS_CC);

	zend_class_implements(xpl_stream_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\http\\message\\streaminterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Creates a new temporary stream.
 *
 * @param string mode [Optional] Default = "w+b". Must be a writable mode.
 * @param int maxMemoryMb [Optional] Default = 2. Max memory used before temporary file.
 *
 * @return \Xpl\Stream
 */
PHP_METHOD(Xpl_Stream, temp) {

	int maxMemoryMb, ZEPHIR_LAST_CALL_STATUS;
	zval *mode_param = NULL, *maxMemoryMb_param = NULL, *filename = NULL, _0$$4;
	zval *mode = NULL, *_1$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &mode_param, &maxMemoryMb_param);

	if (!mode_param) {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "w+b", 1);
	} else {
		zephir_get_strval(mode, mode_param);
	}
	if (!maxMemoryMb_param) {
		maxMemoryMb = 0;
	} else {
		maxMemoryMb = zephir_get_intval(maxMemoryMb_param);
	}


	ZEPHIR_INIT_VAR(filename);
	if (maxMemoryMb == 0) {
		ZVAL_STRING(filename, "php://temp", 1);
	} else {
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_LONG(&_0$$4, ((1048576 * maxMemoryMb)));
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_SV(_1$$4, "php://temp/maxmemory=", &_0$$4);
		ZEPHIR_CPY_WRT(filename, _1$$4);
	}
	object_init_ex(return_value, xpl_stream_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 147, filename, mode);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Constructor.
 *
 * @param string|resource stream
 * @param string mode Mode with which to open stream [Optional] Default = "rb"
 *
 * @throws InvalidArgumentException
 */
PHP_METHOD(Xpl_Stream, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *mode = NULL;
	zval *stream, *mode_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &stream, &mode_param);

	if (!mode_param) {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "rb", 1);
	} else {
		zephir_get_strval(mode, mode_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstream", NULL, 148, stream, mode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Xpl_Stream, __toString) {

	zval *e = NULL, *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isreadable", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontents", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, spl_ce_RuntimeException TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				RETURN_MM_STRING("", 1);
			}
		}
	}
	RETURN_MM_STRING("", 1);

}

/**
 * Returns the underlying resource handle.
 *
 * @return resource|null
 */
PHP_METHOD(Xpl_Stream, getHandle) {

	

	RETURN_MEMBER(this_ptr, "handle");

}

/**
 * Closes the stream and any underlying resources.
 *
 * @return void
 */
PHP_METHOD(Xpl_Stream, close) {

	zval *resourceHandle = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&resourceHandle, this_ptr, "detach", NULL, 0);
		zephir_check_call_status();
		zephir_fclose(resourceHandle TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Separates any underlying resources from the stream.
 *
 * After the stream has been detached, the stream is in an unusable state.
 *
 * @return resource|null Underlying PHP stream, if any
 */
PHP_METHOD(Xpl_Stream, detach) {

	zval *resourceHandle = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(resourceHandle);
	zephir_read_property_this(&resourceHandle, this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 149);
	zephir_check_call_status();
	RETURN_CCTOR(resourceHandle);

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
PHP_METHOD(Xpl_Stream, attach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *mode = NULL;
	zval *resourceHandle, *mode_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceHandle, &mode_param);

	if (unlikely(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_EMPTY_STRING(mode);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstream", NULL, 148, resourceHandle, mode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the size of the stream if known.
 *
 * @return int|null Returns the size in bytes if known, or null if unknown.
 */
PHP_METHOD(Xpl_Stream, getSize) {

	zval *stats = NULL, *size = NULL, *_0, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&stats, "fstat", NULL, 150, _1$$3);
		zephir_check_call_status();
		if (zephir_array_isset_string_fetch(&size, stats, SS("size"), 1 TSRMLS_CC)) {
			RETURN_MM_LONG(zephir_get_intval(size));
		}
	}
	RETURN_MM_NULL();

}

/**
 * Returns the current position of the file read/write pointer
 *
 * @return int Position of the file pointer
 *
 * @throws \RuntimeException on error.
 */
PHP_METHOD(Xpl_Stream, tell) {

	zval *_0, *result = NULL, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "No resource available; cannot tell position", "xpl/stream.zep", 202);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&result, "ftell", NULL, 151, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(result) != IS_LONG) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Error occurred during tell operation", "xpl/stream.zep", 209);
		return;
	}
	RETURN_CCTOR(result);

}

/**
 * Returns true if the stream is at the end of the stream.
 *
 * @return bool
 */
PHP_METHOD(Xpl_Stream, eof) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_feof(_1 TSRMLS_CC));

}

/**
 * Returns whether or not the stream is seekable.
 *
 * @return bool
 */
PHP_METHOD(Xpl_Stream, isSeekable) {

	

	RETURN_MEMBER(this_ptr, "seekable");

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
PHP_METHOD(Xpl_Stream, seek) {

	zval *offset_param = NULL, *whence_param = NULL, *_0, *_1, *result = NULL, *_2, _3, _4;
	int offset, whence, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset_param, &whence_param);

	offset = zephir_get_intval(offset_param);
	if (!whence_param) {
		whence = 0;
	} else {
		whence = zephir_get_intval(whence_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "No resource available; cannot seek position", "xpl/stream.zep", 259);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("seekable"), PH_NOISY_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Stream is not seekable", "xpl/stream.zep", 263);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, offset);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, whence);
	ZEPHIR_CALL_FUNCTION(&result, "fseek", NULL, 152, _2, &_3, &_4);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(result, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Error seeking within stream", "xpl/stream.zep", 270);
		return;
	}
	RETURN_MM_BOOL(1);

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
PHP_METHOD(Xpl_Stream, rewind) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "seek", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether or not the stream is writable.
 *
 * @return bool
 */
PHP_METHOD(Xpl_Stream, isWritable) {

	

	RETURN_MEMBER(this_ptr, "writable");

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
PHP_METHOD(Xpl_Stream, write) {

	zval *str_param = NULL, *result = NULL, *_0, *_1, *_2;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "No resource available; cannot write", "xpl/stream.zep", 317);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("writable"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Stream is not writable", "xpl/stream.zep", 321);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(result);
	zephir_fwrite(result, _2, str TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Error writing to stream", "xpl/stream.zep", 327);
		return;
	}
	RETURN_CCTOR(result);

}

/**
 * Returns whether or not the stream is readable.
 *
 * @return bool
 */
PHP_METHOD(Xpl_Stream, isReadable) {

	

	RETURN_MEMBER(this_ptr, "readable");

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
PHP_METHOD(Xpl_Stream, read) {

	zval *length_param = NULL, *result = NULL, *_0, *_1, *_2, _3;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length_param);

	length = zephir_get_intval(length_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "No resource available; cannot read", "xpl/stream.zep", 360);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("readable"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Stream is not readable", "xpl/stream.zep", 364);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, length);
	ZEPHIR_CALL_FUNCTION(&result, "fread", NULL, 153, _2, &_3);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Error reading stream", "xpl/stream.zep", 370);
		return;
	}
	RETURN_CCTOR(result);

}

/**
 * Returns the remaining contents in a string
 *
 * @return string
 *
 * @throws \RuntimeException if unable to read or an error occurs while
 *     reading.
 */
PHP_METHOD(Xpl_Stream, getContents) {

	zval *result = NULL, *_0, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("handle"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(_0) == IS_NULL)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "No resource available; cannot get contents", "xpl/stream.zep", 389);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("readable"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Stream is not readable", "xpl/stream.zep", 393);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&result, "stream_get_contents", NULL, 93, _2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(result)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Error reading from stream", "xpl/stream.zep", 399);
		return;
	}
	RETURN_CCTOR(result);

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
PHP_METHOD(Xpl_Stream, getMetadata) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *metadata = NULL, *value = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&metadata, "stream_get_meta_data", NULL, 154, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(key) == IS_NULL) {
		RETURN_CCTOR(metadata);
	}
	if (zephir_array_isset_fetch(&value, metadata, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Set the internal stream resource.
 *
 * @param string|resource stream String stream target or stream resource.
 * @param string mode Resource mode for stream target.
 *
 * @throws InvalidArgumentException for invalid streams or resources.
 */
PHP_METHOD(Xpl_Stream, setStream) {

	zend_bool allowRead, allowWrite, _0, _2$$9, _3$$9, _4$$9;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *streamMode = NULL;
	zval *stream, *streamMode_param = NULL, *resourceHandle = NULL, *metadata = NULL, *mode = NULL, *isSeekable = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &stream, &streamMode_param);

	if (unlikely(Z_TYPE_P(streamMode_param) != IS_STRING && Z_TYPE_P(streamMode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'streamMode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(streamMode_param) == IS_STRING)) {
		zephir_get_strval(streamMode, streamMode_param);
	} else {
		ZEPHIR_INIT_VAR(streamMode);
		ZVAL_EMPTY_STRING(streamMode);
	}


	allowRead = 0;
	allowWrite = 0;
	if (Z_TYPE_P(stream) == IS_STRING) {
		ZEPHIR_CALL_FUNCTION(&resourceHandle, "fopen", NULL, 90, stream, streamMode);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(resourceHandle, stream);
	}
	_0 = !(Z_TYPE_P(resourceHandle) == IS_RESOURCE);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "get_resource_type", NULL, 155, resourceHandle);
		zephir_check_call_status();
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(_1, "stream");
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid stream provided; must be a string stream identifier or stream resource", "xpl/stream.zep", 458);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 149);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("handle"), resourceHandle TSRMLS_CC);
	if (!ZEPHIR_IS_IDENTICAL(stream, resourceHandle)) {
		zephir_update_property_this(this_ptr, SL("stream"), stream TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&metadata, "stream_get_meta_data", NULL, 154, resourceHandle);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(mode);
	if (zephir_array_isset_string_fetch(&mode, metadata, SS("mode"), 0 TSRMLS_CC)) {
		if (zephir_memnstr_str(mode, SL("+"), "xpl/stream.zep", 472)) {
			allowRead = 1;
			allowWrite = 1;
		} else {
			if (zephir_memnstr_str(mode, SL("r"), "xpl/stream.zep", 476)) {
				allowRead = 1;
			}
			_2$$9 = zephir_memnstr_str(mode, SL("w"), "xpl/stream.zep", 479);
			if (!(_2$$9)) {
				_2$$9 = zephir_memnstr_str(mode, SL("x"), "xpl/stream.zep", 479);
			}
			_3$$9 = _2$$9;
			if (!(_3$$9)) {
				_3$$9 = zephir_memnstr_str(mode, SL("c"), "xpl/stream.zep", 479);
			}
			_4$$9 = _3$$9;
			if (!(_4$$9)) {
				_4$$9 = zephir_memnstr_str(mode, SL("a"), "xpl/stream.zep", 479);
			}
			if (_4$$9) {
				allowWrite = 1;
			}
		}
	}
	if (allowRead) {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (allowWrite) {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&isSeekable, metadata, SS("seekable"), 1 TSRMLS_CC)) {
		if (zephir_get_boolval(isSeekable)) {
			zephir_update_property_this(this_ptr, SL("seekable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("seekable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Resets the object to its default state.
 */
PHP_METHOD(Xpl_Stream, reset) {

	

	zephir_update_property_this(this_ptr, SL("handle"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("stream"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	if (0) {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("readable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("writable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("seekable"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("seekable"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * Destructor.
 *
 * Closes the resource, just for good measure.
 */
PHP_METHOD(Xpl_Stream, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

