package utils

class NodeNotFound(key: KotlinVersion) : Exception("Node not found: $key")
class IncorrectNodeType : Exception("Cant create DIFF node without FULL one")
class UnknownStorageType(type: StorageType) : Exception("Storage type ($type) is not supported")
class EmptyArrayException(comment: String) : Exception(comment)