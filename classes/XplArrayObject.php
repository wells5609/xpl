<?php
/**
* class XplArrayObject
*
* It's ArrayObject with some helper methods for brevity.
*
* e.g.	offsetGet() 	=> get()
*		offsetUnset()	=> delete()
*		offsetSet()		=> set()
*		offsetExists()	=> exists()
* 
* Can also set defaults as fallbacks for unset properties.
*
* @since 0.3
*/
class XplArrayObject extends ArrayObject {
	
	public $_defaults = array();
	
	public function __construct( array $data = array() ){
		parent::__construct( $data, ArrayObject::ARRAY_AS_PROPS );	
	}
	
	public function exists( $index ){
		return $this->offsetExists( $index );	
	}
	
	public function get( $index, $default = null ){
		if ( null !== $default ){
			$this->setDefault( $index, $default );	
		}
		return $this->offsetExists( $index ) ? $this->offsetGet( $index ) : $this->getDefault( $index );
	}
	
	public function set( $index, $value ){
		return $this->offsetSet( $index, $value );	
	}
	
	public function delete( $index ){
		return $this->offsetUnset( $index );
	}
	
	public function getDefault( $index ){
		return isset( $this->_defaults[ $index ] ) ? $this->_defaults[ $index ] : null;	
	}
	
	public function setDefault( $index, $value ){
		return $this->_defaults[ $index ] = $value;
	}
	
}
