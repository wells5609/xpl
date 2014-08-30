<?php

namespace xpl\Framework\Api;

use xpl\Common\Arrayable;
use xpl\Utility\Arr;

class ResponseStructure implements Arrayable, \IteratorAggregate, \JsonSerializable {
	
	protected $nodes;
	
	protected $keys = array(
		'status' => 'Success',
		'message' => 'Message',
		'errors' => 'Errors',
		'content' => 'Results',
		'diagnostics' => 'Diagnostics',
	);
	
	public function __construct(array $array = null) {
		
		if (empty($array)) {
			$array = array(
				'Success' => '',
				'Message' => '',
				'Errors' => array(),
				'Results' => array(),
				'Diagnostics' => array(),
			);
		} else {
			
			// Check to make sure the structure has the expected node for content
			$content_key = $this->getNodeKey('content');
			
			if (! isset($array[$content_key])) {
				
				$found = false;
			
				// check 1 level deep
				foreach($array as $key => $value) {
					if (is_array($value) && isset($value[$content_key])) {
						$found = true;
						break;
					}
				}
				
				if (! $found) {
					$msg = "Structure must have a node with key '$content_key' in the first or second level.";
					throw new \InvalidArgumentException($msg);
				}
			}
		}
		
		$this->nodes = $array;
	}
	
	public function getNodeKey($section) {
		return isset($this->keys[$section]) ? $this->keys[$section] : null;
	}
	
	public function setStatus($content) {
		$this->setNode($this->getNodeKey('status'), $content);
	}
	
	public function setMessage($content) {
		$this->setNode($this->getNodeKey('message'), $content);
	}
	
	public function setErrors($content) {
		$this->setNode($this->getNodeKey('errors'), $content);
	}
	
	public function setContent($content) {
		$this->setNode($this->getNodeKey('content'), $content);
	}
	
	public function setDiagnostics($content) {
		$this->setNode($this->getNodeKey('diagnostics'), $content);
	}
	
	public function setNode($key, $value) {
		
		if (isset($this->nodes[$key])) {
			$this->nodes[$key] = $value;
		} else {
			Arr::set($this->nodes, $key, $value);
		}
		
		return $this;
	}
	
	public function setNodes(array $data) {
		foreach($data as $key => $value) {
			$this->setNode($key, $value);
		}
		return $this;
	}
	
	public function addNode($key, $subkey, $newval = null) {
			
		if (isset($this->nodes[$key])) {
			$this->nodes[$key][$subkey] = $newval;
		} else {
			Arr::set($this->nodes, $key.'.'.$subkey, $newval);
		}
		
		return $this;
	}
	
	public function removeNode($key) {
			
		if (isset($this->nodes[$key])) {
			unset($this->nodes[$key]);
		} else {
			Arr::remove($this->nodes, $key, null);
		}
		
		return $this;
	}
	
	public function removeNodes(array $data) {
		array_map(array($this, 'removeNode'), $data);
		return $this;
	}
	
	public function getNode($key) {
		return Arr::get($this->nodes, $key);
	}
	
	public function toArray() {
		return $this->nodes;
	}
	
	public function jsonSerialize() {
		return $this->toArray();
	}
	
	public function getIterator() {
		return new \ArrayIterator($this->nodes);
	}
	
}
