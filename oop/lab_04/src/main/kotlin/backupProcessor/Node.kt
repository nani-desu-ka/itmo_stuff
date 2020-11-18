package backupProcessor

import java.io.File

enum class NodeType {
    DELTA,
    FULL
}

enum class StorageType {
    ARCHIVE,
    DIFF
}

abstract class Node {
    abstract val version: KotlinVersion
    abstract val changeList: String
    protected abstract val type: NodeType
    protected abstract val storageType: StorageType
    abstract fun load(): MutableList<File>
}

class DeltaNode(override val version: KotlinVersion, override val storageType: StorageType
                , files: MutableList<File>) : Node() {

    override val changeList: String = TODO("Версия + Список новых строк + список убранных строк")
    override val type = NodeType.DELTA

    init {
        when (storageType) {
            // сохранение файлов
            StorageType.ARCHIVE -> TODO("Сохранение $files в архиве")
            StorageType.DIFF -> TODO("Сохранение $files раздельно")
        }
    }

    override fun load(): MutableList<File> {
        // поиск файлов происходит на основе их версии (будет в названии файла // каталога)
        return when (storageType) {
            StorageType.ARCHIVE -> TODO("Загрузка списка файлов при общем хранении (на основе разницы)")
            StorageType.DIFF -> TODO("Загрузка списка файлов при раздельном хранении (на основе разницы)")
        }
    }
}

class FullNode(override val version: KotlinVersion, override val storageType: StorageType
               , files: MutableList<File>) : Node() {

    override val changeList = "$version\nПолноценная точка сохранения"
    override val type = NodeType.FULL

    init {
        when (storageType) {
            StorageType.ARCHIVE -> TODO("Сохранение $files в архиве")
            StorageType.DIFF -> TODO("Сохранение $files раздельно")
        }
    }

    override fun load(): MutableList<File> {
        // поиск файлов происходит на основе их версии (будет в названии файла // каталога)
        return when (storageType) {
            StorageType.ARCHIVE -> TODO("Загрузка списка файлов при общем хранении")
            StorageType.DIFF -> TODO("Загрузка списка файлов при раздельном хранении")
        }
    }
}
