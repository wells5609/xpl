<?php

use xpl\Platform\StaticFacade;

class Request extends StaticFacade {
	protected static $identifier = 'request';
}

class Response extends StaticFacade {
	protected static $identifier = 'response';
}

class Session extends StaticFacade {
	protected static $identifier = 'session';
}

class Cache extends StaticFacade {
	protected static $identifier = 'cache';
}

class Bundles extends StaticFacade {
	protected static $identifier = 'bundles';
}

class Events extends StaticFacade {
	protected static $identifier = 'events';
}

class Services extends StaticFacade {
	protected static $identifier = 'services';
}

class Api extends StaticFacade {
	protected static $identifier = 'api';
}

class Dbal extends StaticFacade {
	protected static $identifier = 'dbal';
}
