namespace Xpl\Collection;

interface StackInterface extends ListInterface
{

    /**
     * Pushes an item onto the stack.
     *
     * @param mixed
     */
	public function push(var value);

    /**
     * Pops an item off the stack.
     *
     * If the stack is empty, a \UnderflowException must be thrown.
     *
     * @return mixed
     * @throws \UnderflowException if the list is empty (contains no items)
     */
	public function pop();

}
