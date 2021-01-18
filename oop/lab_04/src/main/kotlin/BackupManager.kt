package backupProcessor

import utils.*
import java.io.File
import java.util.*

class BackupManager(deletePreferences: DeletePreferences, vararg storageLimits: StorageLimit) {
    private val _storage = BackupStorage(deletePreferences, *storageLimits)
    private var _latestVersion: KotlinVersion = KotlinVersion(0, 0)

    fun createRestore(files: MutableList<File>, RestoreType: NodeType, storageType: StorageType,
                      updateType: UpdateType, whereToStoreBackUp: String): String {
        _latestVersion = when (updateType) {
            UpdateType.MAJOR -> KotlinVersion(_latestVersion.major + 1, 0)
            UpdateType.MINOR -> KotlinVersion(_latestVersion.major, _latestVersion.minor + 1)
        }
        val newNode: Node
        _storage.get(_latestVersion).returnRoot().childrenAmount += 1
        val fileRestoreCopyInfo = when (RestoreType) {
                NodeType.DELTA -> {
                    if (_storage.isEmpty()) {
                        throw IncorrectNodeType()
                    }
                    newNode = DeltaNode(_latestVersion, storageType, whereToStoreBackUp, files
                        , _storage.get(_latestVersion).returnRoot())
                    newNode.changeList
                }
                NodeType.FULL -> {
                    newNode = FullNode(_latestVersion, storageType, whereToStoreBackUp, files)
                    newNode.changeList
                }
        }
        _storage.add(newNode)
        return fileRestoreCopyInfo
    }
    fun loadRestore(version: KotlinVersion): Node {
        return _storage.get(version)
    }
    fun setNewLimits(vararg storageLimits: StorageLimit): BackupManager {
        _storage.setLimits(*storageLimits)
        return this
    }
    fun setNewDeletePreference(newPreference: DeletePreferences): BackupManager {
        _storage.setDeletePreference(newPreference)
        return this
    }
    fun setDataLimit(newDataLimit: Date): BackupManager {
        _storage.dataLimit = newDataLimit
        return this
    }
    fun setAmountLimit(newAmountLimit: Int): BackupManager {
        _storage.amountLimit = newAmountLimit
        return this
    }
    fun setSizeLimit(newSizeLimit: Int): BackupManager {
        _storage.sizeLimit = newSizeLimit
        return this
    }

}