namespace Xpl;

/**
 * System/server utilities.
 */
class System
{

    public static function sapi() -> string
    {
        return php_sapi_name();
    }

    public static function os() -> string
    {
        return php_uname("s");
    }

    public static function version(var extension = null) -> string
    {
        return phpversion(extension);
    }

    public static function isCli() -> boolean
    {
        return php_sapi_name() === "cli";
    }

    public static function isWin() -> boolean
    {
        return DIRECTORY_SEPARATOR === "\\";
    }

    public static function memoryUsage(boolean megabytes = true) -> float
    {
        if megabytes === true {
            return memory_get_usage() / 1024 / 1024;
        }

        return memory_get_usage();
    }

    public static function memoryPeakUsage(boolean megabytes = true) -> float
    {
        if megabytes === true {
            return memory_get_peak_usage() / 1024 / 1024;
        }

        return memory_get_peak_usage();
    }

    public static function timer(boolean milliseconds = true) -> float | int | null
    {
        if extension_loaded("xdebug") {

            if milliseconds === true {
                return xdebug_time_index() * 1000;
            }

            return xdebug_time_index();
        }

        var startTime;

        if fetch startTime, _SERVER["REQUEST_TIME_FLOAT"] {

            if milliseconds === true {
                return (microtime(true) - startTime) * 1000;
            }

            return microtime(true) - startTime;
        }

        return null;
    }

    public static function apc() -> boolean
    {
        if extension_loaded("apc") {
            // @see http://php.net/manual/en/apc.configuration.php
            if ini_get("apc.enabled") {
                if ! self::isCli() || ini_get("apc.enable_cli") {
                    return true;
                }
            }
        }

        return false;
    }

    public static function apcu() -> boolean
    {
        if extension_loaded("apcu") {
            // @see http://php.net/manual/en/apcu.configuration.php
            if ini_get("apc.enabled") {
                if ! self::isCli() || ini_get("apc.enable_cli") {
                    return true;
                }
            }
        }

        return false;
    }

    public static function xdebug() -> boolean
    {
        return extension_loaded("xdebug");
    }

    public static function mbstring() -> boolean
    {
        return extension_loaded("mbstring");
    }

    public static function normalizePath(string! path) -> string
    {
        return rtrim(str_replace("\\", "/", path), "/\\");
    }

    public static function tempDir() -> string
    {
        return rtrim(sys_get_temp_dir(), "/\\") . DIRECTORY_SEPARATOR;
    }

}
