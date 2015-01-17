<?php

namespace xpl\Common {
	class functions {
		// dummy class
	}
}

namespace {
	
/**
 * Filters a Bin of objects into an array. 
 * 
 * The returned array can have keys pulled from an object field. In addition, one or more fields 
 * can be set as the return value (by default, the object is returned).
 * 
 * @param \xpl\Common\Storage\Bin $objects A Bin instance containing objects.
 * @param string $index_by [Optional] Object field to be used as the item's key in the array.
 * @param string $field [Optional] Object field(s) to be returned as the item's value.
 * 
 * @return array
 */
function xpl_bin_filter(\xpl\Common\Storage\Bin $objects, $index_by = null, $field = null) {
		
	$list = array();
	$isArrayField = isset($field) && is_array($field);
	
	foreach($objects as &$object) {
			
		if (null === $index_by || $object->has($index_by)) {
			
			if (null === $field) {
				$item =& $object;
			
			} else {
			
				if ($isArrayField) {
					// $field is array - filter object data by key
					$item = array_filter_keys($object->toArray(), function ($key) use($field) {
						return in_array($key, $field, true);
					});
			
				} else if ($object->has($field)) {
					// $field is string - return object value
					$item = $object->get($field);
			
				} else {
					continue;
				}
			}
			
			if (null === $index_by) {
				$list[] = $item;
			} else {
				$list[$object->get($index_by)] = $item;
			}
		}
	}
	
	return $list;
}

/**
 * Sorts a collection of objects by field value.
 * 
 * @param \xpl\Common\Storage\Common $collection A collection containing objects.
 * @param string $sort_field Object field name upon which to sort the objects.
 * @param int|string $order [Optional] One of SORT_ASC or SORT_DESC (or "asc" or "desc"). Default SORT_ASC.
 * 
 * @return \xpl\Common\Storage\Collection The sorted collection.
 */
function xpl_collection_sort(\xpl\Common\Storage\Collection $collection, $sort_field, $order = SORT_ASC) {
	
	if (is_string($order)) {
		$order = strtolower($order) === 'asc' ? SORT_ASC : SORT_DESC;
	}
	
	$collection->uasort(function ($a, $b) use($order, $sort_field) {
		
		if (isset($a->$sort_field) && isset($b->$sort_field)) {
			
			if (SORT_ASC === $order) {
				return ($a->$sort_field > $b->$sort_field);
			
			} else {
				return ($a->$sort_field < $b->$sort_field);
			}
		}
	
		return 0;
	});
	
	return $collection;
}

}
