package backupProcessor

import utils.DeletePreferences
import utils.EmptyArrayException
import utils.NodeNotFound
import utils.StorageLimit
import java.util.*

@Suppress("UNREACHABLE_CODE")
class BackupStorage(private var _deletePreference: DeletePreferences, vararg storageLimits: StorageLimit) {
    private var _storage: MutableMap<KotlinVersion, Node> = mutableMapOf()
    private var _storageLimits = storageLimits
    var dataLimit = Date()
    var sizeLimit = 0
    var amountLimit = 0

    fun get(storageKey: KotlinVersion): Node {
        if (!_storage.containsKey(storageKey)) {
            throw NodeNotFound(storageKey)
        } else {
            return _storage[storageKey]!!
        }
    }
    fun add(node: Node) {
        _storage[node.version] = node
        optimizeStorage()
    }
    fun isEmpty(): Boolean {
        return _storage.isEmpty()
    }
    fun setLimits(vararg newLimits: StorageLimit) {
        _storageLimits = newLimits
    }
    fun setDeletePreference(newPreference: DeletePreferences) {
        _deletePreference = newPreference
    }
    private fun optimizeStorage() {
        if (_storageLimits.isEmpty()) {
            throw EmptyArrayException("No limits were given")
        }
        lateinit var bestLimit: StorageLimit
        var bestLimitDeleteAmount: Int
        for ((index, tempLimit) in _storageLimits.withIndex()) {
            val deleteAmount: Int = when (tempLimit) {
                StorageLimit.DATE -> return
                StorageLimit.AMOUNT -> return
                StorageLimit.SIZE -> return
            }
            if (index == 0) {
                bestLimitDeleteAmount = deleteAmount
                bestLimit = tempLimit
            } else {
                if (_deletePreference == DeletePreferences.MORE) {
                    if (deleteAmount > bestLimitDeleteAmount) {
                        bestLimitDeleteAmount = deleteAmount
                        bestLimit = tempLimit
                    }
                } else {
                    if (deleteAmount < bestLimitDeleteAmount) {
                        bestLimitDeleteAmount = deleteAmount
                        bestLimit = tempLimit
                    }
                }
            }
        }
        when (bestLimit) {
            StorageLimit.DATE -> return
            StorageLimit.AMOUNT -> return
            StorageLimit.SIZE -> return
        }
    }
}