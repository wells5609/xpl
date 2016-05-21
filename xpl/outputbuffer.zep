namespace Xpl;

class OutputBuffer
{
	private static root = null;
	private valid = false;
	private level;
	private callback;

	public static function start(var outputCallback = null) -> <OutputBuffer>
    {
		return new self(outputCallback);
	}

	public static function finish() -> boolean
    {
		if self::root !== null {
			self::root->endFlush();
			let self::root = null;
            return true;
		}

		return false;
	}

	public function __construct(var outputCallback = null)
    {
		let this->callback = outputCallback;

		if ob_start(outputCallback) {

			let this->level = ob_get_level();
			let this->valid = true;

			if self::root === null {
				let self::root = this;
			}
		}
	}

	public function getContents() -> string | null
    {
		if this->valid() {
			return ob_get_contents();
		}

        return null;
	}

	public function getClean() -> string | null
    {
		if this->valid() && this->active() {
			let this->valid = false;
			return ob_get_clean();
		}

		return null;
	}

	public function getFullClean() -> string | null
    {
		if ! this->valid() {
			return null;
		}

        var content, level;

		let content = "";
		let level = this->level;

        while ob_get_level() >= level {
			let content = ob_get_clean() . content;
		}

		let this->valid = false;

        return content;
	}

	public function clean() -> boolean
    {
		if this->valid() && this->active() {
			if ob_end_clean() {
				let this->valid = false;
				return true;
			}
		}

		return false;
	}

	public function fullClean() -> boolean
    {
		var level;

		if this->valid() {

			let level = this->level;

			while ob_get_level() >= level {
				if ! ob_end_clean() {
					break;
				}
			}

			let this->valid = false;
			return true;
		}

		return false;
	}

	public function flush() -> void
    {
		var level;

		if this->valid() {

			let level = this->level;

			while ob_get_level() >= level {
				ob_flush();
			}
		}
	}

	public function endFlush() -> boolean
    {
		var level;

		if this->valid() {

			let level = this->level;

			while ob_get_level() >= level {
				if ! ob_end_flush() {
					return false;
				}
			}

			return true;
		}

		return false;
	}

	public function valid() -> boolean
    {
        if this->valid === true {
			if ob_get_level() < this->level {
				let this->valid = false;
			}
		}

		return this->valid;
	}

	public function active() -> boolean
    {
		return ob_get_level() === this->level;
	}

	public function getLevel() -> int
    {
		return this->level;
	}

	public function getOutputCallback() -> var | null
	{
		return this->callback;
	}

}
