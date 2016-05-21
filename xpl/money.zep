namespace Xpl;

use NumberFormatter;

/**
 * Money represents a generic monetary unit.
 */
class Money extends Number
{

    /**
     * Formats the number.
     *
     * @param int decimals
     * @return string
     */
	public function format(int decimals = 2) -> string
    {
		var locale, formatter;

		let locale = this->getLocale();

		if typeof locale == "string" {
			let formatter = new NumberFormatter(locale, NumberFormatter::CURRENCY);
			return formatter->format(this->asString());
		}

		return parent::format(decimals);
	}

	public function getNumberFormatter(var locale = null) -> <NumberFormatter>
	{
		if typeof locale == "null" || empty locale {
			let locale = this->getLocale();
		}

		return new NumberFormatter(locale, NumberFormatter::CURRENCY);
	}

	public function getLocale() -> string | boolean
	{
		return setlocale(LC_ALL, "0");
	}

}
