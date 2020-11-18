import backupProcessor.BackupManager
import utils.*
import java.io.File

fun main() {
    val backuper = BackupManager()
    val someFile = File("SomePathWhereFileStored")
    println(backuper.CreateRestore(mutableListOf(someFile),
        NodeType.FULL, StorageType.ARCHIVE, UpdateType.MAJOR,
        "SomePathForBackup"))
    println(backuper.LoadRestore(KotlinVersion(1, 0)))
}