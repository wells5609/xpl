namespace Xpl\Collection;

interface QueueInterface extends ListInterface
{

    /**
     * Enqueues an item onto the list.
     *
     * @param mixed value
     */
	public function enqueue(var value);

    /**
     * Dequeues an item off the list.
     *
     * If the list is empty, a \UnderflowException must be thrown.
     *
     * @return mixed
     *
     * @throws \UnderflowException if the list is empty (contains no items)
     */
	public function dequeue();

}
