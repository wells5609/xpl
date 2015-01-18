#Framework

The `Framework` package includes a set of classes to easily start application development.

Of particular note:
  * `DI` - the framework DI sets up a number of default components in the constructor.
  * `Env` - this class holds information on the current environment.
  * `Application` - this namespace includes an extended `App` class, as well as a factory, configuration, and info class.
  * `Kernel` - the kernel is the application shell. It is essentially a wrapper for the routing and dispatching processes.
