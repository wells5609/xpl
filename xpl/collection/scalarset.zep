namespace Xpl\Collection;

use Xpl\Type;
use SplObjectStorage;
use InvalidArgumentException;

class ScalarSet extends SplObjectStorage implements SetInterface
{

	public function add(var value)
    {
        parent::attach(self::cast(value));
	}

	public function remove(var value, var inf = null)
    {
		parent::detach(self::cast(value));
	}

    public function attach(var value, var inf = null)
    {
        this->add(value);
    }

    public function detach(var value, var inf = null)
    {
        this->remove(value);
    }

	public function contains(var value) -> boolean
	{
		return parent::contains(self::cast(value));
	}

	public function getHash(var obj) -> string
	{
		return (string) obj->{"scalar"};
	}

    public function isEmpty() -> boolean
    {
        return this->count() === 0;
    }

    public function toArray() -> array
    {
        return iterator_to_array(this);
    }

    public function addAll(var data)
    {
        var value;
        for value in Type::iterate(data) {
            this->add(value);
        }
    }

	public static function cast(var value) -> object
	{
		if likely (typeof value == "null" || is_scalar(value)) {
			return (object)["scalar": value];
		}

		throw new InvalidArgumentException("Expecting null or scalar, given: " . gettype(value));
	}

}
