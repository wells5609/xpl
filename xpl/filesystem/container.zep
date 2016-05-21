namespace Xpl\Filesystem;

use InvalidArgumentException;

class Container implements \Countable
{

    /**
     * @var string
     */
    protected rootPath {
        get
    };

    /**
     * @var array
     */
    protected paths = [];

    public function __construct(string rootPath) -> void
    {
        var realpath;
        let realpath = realpath(rootPath);

        if realpath === false || ! is_dir(realpath) {
            throw new InvalidArgumentException("Invalid base directory path");
        }

        let this->rootPath = realpath . DIRECTORY_SEPARATOR;
    }

    public function setPaths(array paths) -> <Container>
    {
        var path;

        for path in paths {
            this->addPath(path);
        }

        return this;
    }

    public function getPaths() -> array
    {
        return this->paths;
    }

    public function addPath(string path) -> <Container>
    {
        var realpath;
        let realpath = realpath(path);

        if realpath === false || ! is_dir(realpath) {
            throw new InvalidArgumentException("Invalid directory path: " . path);
        }

        let this->paths[] = realpath . DIRECTORY_SEPARATOR;

        return this;
    }

    public function hasPath(string path) -> boolean
    {
        var realpath;
        let realpath = realpath(path);

        if realpath === false || ! is_dir(realpath) {
            return false;
        }

        if realpath === this->rootPath {
            return true;
        }

        return in_array(realpath, this->paths, true);
    }

    public function getRelativePath(string path) -> string | null
    {
        var realpath;
        let realpath = realpath(path);

        if realpath === false || ! starts_with(realpath, this->rootPath) {
            return null;
        }

        return substr(realpath, strlen(this->rootPath));
    }

    public function find(string filename) -> string | null
    {
        var path;
        string file;

        let filename = ltrim(filename, "/\\");
        let file = this->rootPath . filename;

        if file_exists(file) {
            return file;
        }

        for path in this->paths {
            let file = path . filename;
            if file_exists(file) {
                return file;
            }
        }

        return null;
    }

    public function search(string filename) -> array | null
    {
        var path;
        string file;
        array files = [];

        let filename = ltrim(filename, "/\\");
        let file = this->rootPath . filename;

        if file_exists(file) {
            let files[] = file;
        }

        for path in this->paths {
            let file = path . filename;
            if file_exists(file) {
                let files[] = file;
            }
        }

        return empty files ? null : files;
    }

    public function count() -> int
    {
        return count(this->paths) + 1;
    }

}
