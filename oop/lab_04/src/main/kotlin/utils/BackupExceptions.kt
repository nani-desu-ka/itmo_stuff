package utils

class NodeNotFound(key: KotlinVersion) : Exception("Node not found: $key")
class UnknownStorageType(type: StorageType) : Exception("Storage type ($type) is not supported")