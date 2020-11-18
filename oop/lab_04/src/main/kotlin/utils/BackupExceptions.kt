package utils

class NodeNotFound(key: KotlinVersion) : Exception("Node not found: $key")
class NoParticipantsFound : Exception("Race without participants")
