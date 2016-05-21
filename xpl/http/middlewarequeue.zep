namespace Xpl\Http;

use Xpl\Collection\Queue;
use InvalidArgumentException;

class MiddlewareQueue extends Queue
{

	public function enqueue(var middleware)
	{
		self::assertValidMiddleware(middleware);
		parent::enqueue(middleware);
	}

	public function offsetSet(var index, var value)
    {
		self::assertValidMiddleware(value);
		parent::offsetSet(index, value);
	}

	public function push(var middleware)
    {
		self::assertValidMiddleware(middleware);
		parent::push(middleware);
	}

	public function attach(var middleware)
    {
		self::assertValidMiddleware(middleware);
		this->enqueue(middleware);
	}

	public function unshift(var middleware)
    {
		self::assertValidMiddleware(middleware);
		parent::unshift(middleware);
	}

	public static function assertValidMiddleware(var middleware)
	{
		if typeof middleware == "object" {
			if middleware instanceof \Closure || method_exists(middleware, "__invoke") {
				return true;
			}
		}

		throw new InvalidArgumentException("Middleware must be Closure or object with __invoke method");
	}

}
