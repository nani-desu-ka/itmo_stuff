package backupProcessor

import utils.NodeNotFound

class BackupStorage {
    private var _storage: MutableMap<KotlinVersion, Node> = mutableMapOf()
    fun get(storageKey: KotlinVersion): Node {
        if (!_storage.containsKey(storageKey)) {
            throw NodeNotFound(storageKey)
        } else {
            return _storage[storageKey]!!
        }
    }
    fun add(key: KotlinVersion, node: Node) {
        _storage[key] = node
    }
}