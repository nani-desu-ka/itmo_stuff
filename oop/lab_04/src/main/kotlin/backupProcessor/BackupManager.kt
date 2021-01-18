package backupProcessor

import utils.NodeType
import utils.StorageType
import utils.UpdateType
import java.io.File

class BackupManager {
    private val _storage = BackupStorage()
    private var _latestVersion: KotlinVersion = KotlinVersion(0, 0)

    fun CreateRestore(files: MutableList<File>, RestoreType: NodeType, storageType: StorageType,
                      updateType: UpdateType, whereToStoreBackUp: String): String {
        _latestVersion = when (updateType) {
            UpdateType.MAJOR -> KotlinVersion(_latestVersion.major + 1, 0)
            UpdateType.MINOR -> KotlinVersion(_latestVersion.major, _latestVersion.minor + 1)
        }
        val newNode: Node
        val fileRestoreCopyInfo = when (RestoreType) {
                NodeType.DELTA -> {
                    newNode = DeltaNode(_latestVersion, storageType, whereToStoreBackUp, files)
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
    fun LoadRestore(version: KotlinVersion) {
        _storage.get(version)
    }
}