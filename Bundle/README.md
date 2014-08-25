#Bundle

A bundle is an abstract runtime "package". 

The key features of a bundle are:
 * __Loadability__ - they can be loaded automatically, on-demand, or not all
 * __Replacement__ - they can replace other existing bundles
 * __Dependencies__ - they can use other bundles and load them when required


Every bundle has a "type". Three types are included: 
 * `library` - represents a directory of files. When loaded, a `bootstrap.php` file is included.
 * `application` - represents an application or app module
 * `plugin` - an abstract bundle whose behavior depends on the implementation
 

```php
$bundles = new \xpl\Bundle\Manager;

$bundles->provideType('library', function ($type, $name) {
	
  $dir = __DIR__."/Library/{$name}/";
	
	if (is_dir($dir)) {
	  return new \xpl\Bundle\Library($dir);
	}
}

// when needed:
$bundles->boot('library.MyLib'); // loads Library/MyLib/bootstrap.php


