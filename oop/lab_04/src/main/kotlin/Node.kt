package backupProcessor

import utils.NodeType
import utils.StorageType
import utils.UnknownStorageType
import java.io.File
import java.util.*

abstract class Node {
    var childrenAmount: Int = 0
    abstract val version: KotlinVersion
    abstract val changeList: String
    abstract val date: Date
    abstract val type: NodeType
    protected abstract val _path: String
    protected abstract val _files: MutableList<File>
    protected abstract val _storageType: StorageType

    abstract fun load(): MutableList<File>
    abstract fun returnRoot(): Node
    open fun delete() {
        return
    }
}

class DeltaNode(override val version: KotlinVersion, override val _storageType: StorageType
                , override val _path: String, override val _files: MutableList<File>
                , val rootNode: Node) : Node() {

    override val date = Date()
    override val changeList: String = ""
    override val type = NodeType.DELTA
    init {
        when (_storageType) {
            // сохранение файлов
            StorageType.ARCHIVE -> throw UnknownStorageType(_storageType)
            StorageType.DIFF -> throw UnknownStorageType(_storageType)
            else -> throw UnknownStorageType(_storageType)
        }
    }

    override fun load(): MutableList<File> {
        return when (_storageType) {
            StorageType.ARCHIVE -> return _files
            StorageType.DIFF -> return _files
            else -> throw UnknownStorageType(_storageType)
        }
    }
    override fun returnRoot(): Node {
        return rootNode.returnRoot()
    }

    override fun delete() {
        returnRoot().childrenAmount -= 1
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
            StorageType.ARCHIVE -> throw UnknownStorageType(_storageType)
            StorageType.DIFF -> throw UnknownStorageType(_storageType)
            else -> throw UnknownStorageType(_storageType)
        }
    }

    override fun load(): MutableList<File> {
        return when (_storageType) {
            StorageType.ARCHIVE -> throw UnknownStorageType(_storageType)
            StorageType.DIFF -> throw UnknownStorageType(_storageType)
            else -> throw UnknownStorageType(_storageType)
        }
    }

    override fun returnRoot(): Node {
        return this
    }
}
