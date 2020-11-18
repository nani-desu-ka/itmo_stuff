package backupProcessor

import utils.NodeType
import utils.StorageType
import utils.UnknownStorageType
import java.io.File
import java.util.*

abstract class Node {
    abstract val version: KotlinVersion
    abstract val changeList: String
    abstract val date: Date
    abstract val type: NodeType
    protected abstract val _path: String
    protected abstract val _files: MutableList<File>
    protected abstract val _storageType: StorageType

    abstract fun load(): MutableList<File>
}

class DeltaNode(override val version: KotlinVersion, override val _storageType: StorageType
                , override val _path: String, override val _files: MutableList<File>) : Node() {

    override val date = Date()
    override val changeList: String = TODO("Версия + Список новых строк + список убранных строк")
    override val type = NodeType.DELTA

    init {
        when (_storageType) {
            // сохранение файлов
            StorageType.ARCHIVE -> TODO("Сохранение $_files в архиве")
            StorageType.DIFF -> TODO("Сохранение $_files раздельно")
            else -> throw UnknownStorageType(_storageType)
        }
    }

    override fun load(): MutableList<File> {
        return when (_storageType) {
            StorageType.ARCHIVE -> TODO("Загрузка списка файлов при общем хранении (на основе разницы)")
            StorageType.DIFF -> TODO("Загрузка списка файлов при раздельном хранении (на основе разницы)")
            else -> throw UnknownStorageType(_storageType)
        }
    }
}

class FullNode(override val version: KotlinVersion, override val _storageType: StorageType
               , override val _path: String, override val _files: MutableList<File>) : Node() {

    override val date = Date()
    override val changeList = "$version\nПолноценная точка сохранения"
    override val type = NodeType.FULL

    init {
        when (_storageType) {
            // сохранение файлов
            StorageType.ARCHIVE -> TODO("Сохранение $_files в архиве")
            StorageType.DIFF -> TODO("Сохранение $_files раздельно")
            else -> throw UnknownStorageType(_storageType)
        }
    }

    override fun load(): MutableList<File> {
        return when (_storageType) {
            StorageType.ARCHIVE -> TODO("Загрузка списка файлов при общем хранении")
            StorageType.DIFF -> TODO("Загрузка списка файлов при раздельном хранении")
            else -> throw UnknownStorageType(_storageType)
        }
    }
}
