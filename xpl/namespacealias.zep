namespace Xpl;

class NamespaceAlias
{

	/**
	 * Original namespace.
	 *
	 * @var string
	 */
	private original;

	/**
	 * Namespace alias.
	 *
	 * @var string
	 */
	private alias;

	/**
	 * Length of the alias namespace.
	 *
	 * @var int
	 */
	private aliasLength;

	/**
	 * Classes in the aliased namespace that have been resolved.
	 *
	 * @var array
	 */
	private resolved = [];

	/**
	 * Constructor. Sets the original and alias namespace.
	 *
	 * @param string original Actual namespace name.
	 * @param string alias Alias namespace to use in code.
	 */
	public function __construct(string! original, string! alias)
    {
		let this->original = trim(original, "\\") . "\\";
		let this->alias = trim(alias, "\\") . "\\";
		let this->aliasLength = strlen(this->alias);
	}

	/**
	 * Autoloader implementation to resolve classes in the aliased namespace.
	 *
	 * @param string classname
	 */
	public function load(string classname)
    {
        var realClass;

		if starts_with(classname, this->alias) {

			let realClass = this->original . substr(classname, this->aliasLength);

			if class_exists(realClass) {

				let this->resolved[classname] = realClass;

				class_alias(realClass, classname);
			}
		}
	}

	/**
	 * Returns an array of classes that have been resolved.
	 *
	 * @return array
	 */
	public function getResolved() -> array
    {
		return this->resolved;
	}

	/**
	 * Registers the autoloader.
	 *
	 * @return \Xpl\NamespaceAlias
	 */
	public function register() -> <NamespaceAlias>
    {
		// loader must not be prepended
		spl_autoload_register([this, "load"], true, false);
        return this;
	}

	/**
	 * Unregisters the autoloader.
	 *
	 * @return \Xpl\NamespaceAlias
	 */
	public function unregister() -> <NamespaceAlias>
    {
		spl_autoload_unregister([this, "load"]);
        return this;
	}

}
