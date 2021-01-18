package utils

enum class NodeType {
    DELTA,
    FULL
}

enum class StorageType {
    ARCHIVE,
    DIFF
}

enum class UpdateType {
    MAJOR,
    MINOR
}

enum class StorageLimit {
    DATE,
    AMOUNT,
    SIZE,
    HYBRID
}