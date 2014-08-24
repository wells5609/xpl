<?php

namespace xpl\Common\Storage;

use xpl\Common\Sortable;
use xpl\Common\Structure\StackInterface;

/**
 * Collection is a KeyList that implements Indexed and Sortable.
 * 
 * It also has several methods that mimic those of several array_*() functions.
 */
class Collection extends \xpl\Common\Structure\Base implements StackInterface, Sortable {
	
	/**
	 * Collection accepts null as a key (item key will be an index).
	 * 
	 * @param string|NULL $key
	 * @param mixed $value
	 */
	public function set($key, $value) {
		if (null === $key) {
			$this->_data[] = $value;
		} else {
			$this->_data[$key] = $value;
		}
	}
	
	/**
	 * Clears the collection, removing all items.
	 * 
	 * @return void
	 */
	public function clear() {
		$this->_data = array();
	}
	
	public function attach($value, $prepend = false) {
		
		if ($prepend) {
			return array_unshift($this->_data, $value);
		}
		
		return array_push($this->_data, $value);
	}
	
	public function detach($value) {
		if ($key = array_search($value, $this->_data, true)) {
			$item = $this->_data[$key];
			unset($this->_data[$key]);
			return $item;
		}
		return null;
	}
	
	public function push($value) {
		return array_push($this->_data, $value);
	}
	
	public function pop() {
		return array_pop($this->_data);
	}
	
	public function unshift($value) {
		return array_unshift($this->_data, $value);
	}
	
	public function shift() {
		return array_shift($this->_data);
	}

	public function walk($callback, $userdata = null) {
		return array_walk($this->_data, $callback, $userdata);
	}
	
	/**
	 * Merges the given items into the collection.
	 * 
	 * @param array|Arrayable $data
	 * @return void
	 */
	public function merge($data) {

		if (! is_array($data)) {
				
			if (! $data instanceof Arrayable) {
				throw new \InvalidArgumentException("Data must be array or Arrayable, given ".gettype($data));
			}
			
			$data = $data->toArray();
		}

		if (! isset($this->_data)) {
			$this->_data = array();
		}

		$this->_data = array_merge($this->_data, $data);
	}
	
	/**
	 * Replaces items in the collection with those given.
	 * 
	 * @param array|Arrayable $data
	 * @return void
	 */
	public function replace($data) {

		if (! is_array($data)) {
			
			if (! $data instanceof Arrayable) {
				throw new \InvalidArgumentException("Data must be array or Arrayable, given ".gettype($data));
			}
			
			$data = $data->toArray();
		}

		if (! isset($this->_data)) {
			$this->_data = array();
		}

		$this->_data = array_replace($this->_data, $data);
	}
	
	/**
	 * Filters the elements using a callback function and returns a new collection.
	 * 
	 * @return \xpl\Common\Storage\Collection
	 */
	public function filter($func) {
		return new static(array_filter($this->items, $func));
	}
	
	/**
	 * Applies a callback function to each element and returns a new Collection.
	 * 
	 * @param callable $func
	 * @return \xpl\Common\Storage\Collection
	 */
	public function map($func) {
		return new static(array_map($func, $this->items));
	}
	
	/**
	 * Extracts a slice of the list and returns a new Collection.
	 * 
	 * @param integer $offset Position to start extracting items at.
	 * @param integer $length [Optional] Number of items to extract.
	 * @return \xpl\Common\Storage\Collection
	 */
	public function slice($offset, $length = null) {
		return new static(array_slice($this->_data, $offset, $length, true));
	}
	
	/**
	 * Computes the intersection with the given array and returns a new Collection.
	 * 
	 * @param array|\xpl\Common\Arrayable $data
	 * @return \xpl\Common\Storage\Collection
	 */
	public function intersect($data) {
		
		if (! is_array($data)) {
			if (! $data instanceof Arrayable) {
				throw new InvalidArgumentException("Data must be array or Arrayable, given ".gettype($data));
			}
			$data = $data->toArray();
		}
		
		return new static(array_intersect_assoc($this->_data, $data));
	}
	
	/**
	 * Returns a new Collection containing items do not appear in $data.
	 * 
	 * @param array|\xpl\Common\Arrayable
	 * @return \xpl\Common\Storage\Collection
	 */
	public function diff($data) {

		if (! is_array($data)) {
			if (! $data instanceof Arrayable) {
				throw new InvalidArgumentException("Data must be array or Arrayable, given ".gettype($data));
			}
			$data = $data->toArray();
		}

		return new static(array_diff_assoc($this->_data, $data));
	}

	/**
	 * Returns a new collection containing items whose keys do not appear in $data. 
	 * 
	 * @param array|\xpl\Common\Arrayable $data
	 * @return \xpl\Common\Storage\Collection
	 */
	public function keyDiff($data) {

		if (! is_array($data)) {
			
			if (! $data instanceof Arrayable) {
				throw new InvalidArgumentException("Elements must be array or Arrayable - given ".gettype($data));
			}
			
			$data = $data->toArray();
		}

		return new static(array_diff_key($this->_data, $data));
	}
	
	/**
	 * Filters the element keys and returns a new Collection.
	 * 
	 * @param callable $func
	 * @return \xpl\Common\Storage\Collection
	 */
	public function keyFilter($func) {
		$filtered = array_filter($this->getKeys(), $func);
		return new static(array_intersect_key($this->_data, array_flip($filtered)));
	}
	
	/**
	 * Applies a callback function to each element key and returns a new collection.
	 * 
	 * @param callable $func
	 * @return \xpl\Common\Storage\Collection
	 */
	public function keyMap($func) {
		return new static(array_combine(array_map($func, $this->getKeys()), $this->getValues()));
	}
	
	/**
	 * @param \Closure $func
	 */
	public function each(\Closure $func) {
		
		$func->bindTo($this, $this);
		
		$this->first();
		
		while ($this->valid()) {
			$func($this->current(), $this->key());
			$this->next();
		}
	}
	
	/**
	 * Returns the sum of the collection values.
	 * 
	 * @return int|float
	 */
	public function sum() {
		return array_sum($this->_data);
	}
	
	/**
	 * Returns the product of the collection values.
	 * 
	 * @return int|float
	 */
	public function product() {
		return array_product($this->_data);
	}
	
	/**
	 * Selects 1 or more random keys from the collection.
	 * 
	 * @param integer $num Number of keys to retrieve
	 * @return mixed Returns the key if $num = 1, otherwise an indexed array of keys.
	 */
	public function rand($num = 1) {
		return array_rand($this->_data, $num);
	}
	
	public function asort() {
		return asort($this->_data);
	}

	public function ksort() {
		return ksort($this->_data);
	}

	public function natsort() {
		return natsort($this->_data);
	}

	public function natcasesort() {
		return natcasesort($this->_data);
	}

	public function uasort($func) {
		return uasort($this->_data, $func);
	}

	public function uksort($func) {
		return uksort($this->_data, $func);
	}
	
	/**
	 * Magic __get()
	 *
	 * @param string|int $var Element key/index.
	 * @return mixed
	 */
	public function __get($var) {
		return $this->get($var);
	}

	/**
	 * Magic __set()
	 *
	 * @param string|int $var Element key/index.
	 * @param mixed $val Element value.
	 * @return void
	 */
	public function __set($var, $val) {
		$this->set($var, $val);
	}

	/**
	 * Magic __isset()
	 *
	 * @param string|int $var Element key/index.
	 * @return boolean
	 */
	public function __isset($var) {
		return $this->exists($var);
	}

	/**
	 * Magic __unset()
	 *
	 * @param string|int $var Element key/index.
	 * @return void
	 */
	public function __unset($var) {
		$this->remove($var);
	}
}
