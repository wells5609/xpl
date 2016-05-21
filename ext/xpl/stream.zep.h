
extern zend_class_entry *xpl_stream_ce;

ZEPHIR_INIT_CLASS(Xpl_Stream);

PHP_METHOD(Xpl_Stream, temp);
PHP_METHOD(Xpl_Stream, __construct);
PHP_METHOD(Xpl_Stream, __toString);
PHP_METHOD(Xpl_Stream, getHandle);
PHP_METHOD(Xpl_Stream, close);
PHP_METHOD(Xpl_Stream, detach);
PHP_METHOD(Xpl_Stream, attach);
PHP_METHOD(Xpl_Stream, getSize);
PHP_METHOD(Xpl_Stream, tell);
PHP_METHOD(Xpl_Stream, eof);
PHP_METHOD(Xpl_Stream, isSeekable);
PHP_METHOD(Xpl_Stream, seek);
PHP_METHOD(Xpl_Stream, rewind);
PHP_METHOD(Xpl_Stream, isWritable);
PHP_METHOD(Xpl_Stream, write);
PHP_METHOD(Xpl_Stream, isReadable);
PHP_METHOD(Xpl_Stream, read);
PHP_METHOD(Xpl_Stream, getContents);
PHP_METHOD(Xpl_Stream, getMetadata);
PHP_METHOD(Xpl_Stream, setStream);
PHP_METHOD(Xpl_Stream, reset);
PHP_METHOD(Xpl_Stream, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_temp, 0, 0, 0)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, maxMemoryMb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceHandle)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_write, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_read, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_getmetadata, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stream_setstream, 0, 0, 2)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_INFO(0, streamMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_stream_method_entry) {
	PHP_ME(Xpl_Stream, temp, arginfo_xpl_stream_temp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Stream, __construct, arginfo_xpl_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Stream, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, getHandle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, detach, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, attach, arginfo_xpl_stream_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, tell, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, eof, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, isSeekable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, seek, arginfo_xpl_stream_seek, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, isWritable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, write, arginfo_xpl_stream_write, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, isReadable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, read, arginfo_xpl_stream_read, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, getContents, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, getMetadata, arginfo_xpl_stream_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Stream, setStream, arginfo_xpl_stream_setstream, ZEND_ACC_PRIVATE)
	PHP_ME(Xpl_Stream, reset, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Xpl_Stream, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
