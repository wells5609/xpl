namespace Xpl;

class Rate extends Number
{

	public function __construct(var number, var precision = null) {
		parent::__construct(self::parsePercent(number), precision);
	}

	public function format(int decimals = 2, boolean appendPctSign = true) -> string
    {
        var formatted;
        let formatted = number_format(Math::mul(this->value, 100), decimals);
        if appendPctSign === true {
            let formatted .= "%";
        }
        return formatted;
	}

	public static function parsePercent(var number) -> var
    {
		if typeof number == "string" {
            if substr(number, -1) === "%" {
    			return Math::div(rtrim(number, "%"), 100);
            }
		}
		return number;
	}
}
