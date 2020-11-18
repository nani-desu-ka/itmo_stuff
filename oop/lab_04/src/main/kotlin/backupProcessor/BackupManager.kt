package backupProcessor

import java.nio.file.Files

class BackupManager {
    private val _storage = BackupStorage()
    fun CreateRestore(files: MutableList<Files>, RestoreType: NodeType, version: KotlinVersion): String {
        val fileInfo = FileInfo(Filepath)
        val fileRestoreCopyInfo = when (RestoreType) {
                NodeType.DELTA -> {
                    val newNode = DeltaNode(files, fileInfo.Size, DataTime.Now)
                    _storage.add(newNode.version, newNode)
                    newNode.changeList
                }
                NodeType.FULL -> {
                    val newNode = FullNode(files, fileInfo.Size, DataTime.Now)
                    _storage.add(newNode.version, newNode)
                    newNode.changeList
                }
//    File.Copy(filePath, _pathWhereWeNeedToStoreOurBackup)
        }
        return fileRestoreCopyInfo
    }
    fun LoadRestore(version: KotlinVersion) {
        _storage.get(version)
    }
}