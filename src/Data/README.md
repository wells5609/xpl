#Data

The data package includes a set of interfaces and classes that can be used to create a decoupled, source-agnostic system for data retrieval and storage.

###Package components

 * __Service__ - A "service" is the user-facing interface of the data storage system. The service defines any data-specific functionality and encapsulates all operations on the underlying sub-system components.
 * __Provider__ - A "provider" provides a link between the service and its storage component.
 * __Adapter__ - An "adapter" provides a common interface to a data storage sub-system. For example, you may have an adapter for file storage, a PDO-based database, etc.
 * __Factory__ - A "factory" is used to create PHP objects based on your data model.

###Basic workflow
 1. User requests an entity from a Service.
 2. Service asks its Provider to fetch the data.
 3. Provider relays the request to its Adapter.
 4. Adapter fetches and returns the data.
 5. Provider asks Factory to create PHP objects from the data.
 6. Factory returns the PHP object.
 7. Provider returns object to Service.
 8. Service returns object to user.
