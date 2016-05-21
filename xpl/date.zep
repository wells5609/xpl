namespace Xpl;

use DateTime;
use DateTimeZone;
use InvalidArgumentException;

class Date
{

    const MINUTE = 60;
    const HOUR   = 3600;
    const DAY    = 86400;
    const WEEK   = 604800;
    const MONTH  = 2592000; // 30 days
    const YEAR   = 31536000; // 365 days

    const FORMAT_HUMAN = "d M Y H:i";
    const FORMAT_SQL = "Y-m-d H:i:s";

    public static function isValid(var dateTime) -> boolean
    {
        var time;

        if dateTime instanceof DateTime {
            return true;
        }

        let time = strtotime(dateTime);

        return time > 0;
    }

    public static function time(var time = null) -> int
    {
        if typeof time == "null" {
            return time();
        }

        if time instanceof DateTime {
            return time->format("U");
        }

        if is_numeric(time) {
            let time = (int)time;
        } else {
            let time = strtotime(time);
        }

        return time ? time : 0;
    }

    public static function make(var time = null, var timezone = null) -> <DateTime>
    {
        var dateObject;

        let timezone = self::timezone(timezone);

        if typeof time == "object" {
            if time instanceof DateTime {
                return time->setTimezone(timezone);
            } else {
                throw new InvalidArgumentException("Object argument must be DateTime, given: " . get_class(time));
            }
        }

        let dateObject = new DateTime("@" . self::time(time));

        dateObject->setTimezone(timezone);

        return dateObject;
    }

    public static function timezone(var timezone = null) -> <DateTimeZone>
    {
        if typeof timezone == "null" {
            let timezone = date_default_timezone_get();
        } else {
            if timezone instanceof DateTimeZone {
                return timezone;
            }
        }

        return new DateTimeZone(timezone);
    }

    public static function format(var dateTime, string format) -> string
    {
        return self::make(dateTime)->format(format);
    }

    public static function formatHuman(var dateTime, var format = null) -> string
    {
        if typeof format == "null" {
            let format = self::FORMAT_HUMAN;
        }

        return self::make(dateTime)->format(format);
    }

    public static function formatSql(var dateTime) -> string
    {
        return self::make(dateTime)->format(self::FORMAT_SQL);
    }

}
