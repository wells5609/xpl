<?php

require_once __DIR__.'/Utility/ClassUtils/Autoloader.php';

return \xpl\Utility\ClassUtils\Autoloader::instance('xpl')->setMode(1)->setPath(__DIR__)->register(true);