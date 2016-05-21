namespace Xpl;

class Apcu
{
    const DEFAULT_TTL = 3600;

    private static prefix = "";

    public static function loaded() -> boolean
    {
        return extension_loaded("apcu");
    }

    public static function enabled() -> boolean
    {
        return function_exists("apcu_enabled") && apcu_enabled();
    }

    public static function setPrefix(string! prefix) -> void
    {
        let self::prefix = rtrim(prefix, ".") . ".";
    }

    public static function getPrefix() -> string
    {
        return self::prefix;
    }

    public static function get(string! key) -> var | null
    {
        return apcu_fetch(self::prefix . key);
    }

    public static function set(string! key, var value, int ttl = self::DEFAULT_TTL) -> void
    {
        apcu_store(self::prefix . key, value, ttl);
    }

    public static function exists(string! key) -> boolean
    {
        return apcu_exists(self::prefix . key);
    }

    public static function delete(string! key) -> void
    {
        apcu_delete(self::prefix . key);
    }

    public static function clear() -> void
    {
        apcu_clear_cache();
    }

    public static function expiry(string! key) -> int | null
    {
        var info, ttl, mtime;

        let info = apcu_key_info(self::prefix . key);

        if typeof info == "array" {
            if fetch ttl, info["ttl"] {
				if fetch mtime, info["mtime"] {
					return mtime + ttl;
				}
			}
        }

        return null;
    }

}
