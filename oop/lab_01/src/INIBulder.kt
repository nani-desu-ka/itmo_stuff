import java.io.File
import java.io.FileNotFoundException

enum class Type {
    Cint,
    Cfloat,
    Cstring,
}

@Suppress("UNCHECKED_CAST")
class INIBuilder(fileName: String) {
    private var inputFile = File(fileName)
    private val _sections = ArrayList<Section>()
    init {
        if (!inputFile.exists()) {
            throw FileNotFoundException("File not found")
        }
        if (inputFile.extension != "INI") {
            throw FileNotFoundException("Incorrect file extension")
        }
        val inputStream = inputFile.inputStream()
        val text = inputStream.bufferedReader().readLines()
        var sectionName = ""
        val sectionInfo = ArrayList<String>()
        for (line in text) {
            if (line.replace(Regex("[^\\[=\\]]+"), "").isNotEmpty()) {
                when (line.replace(Regex("[^\\[=\\]]+"), "")[0]) {
                    '[' -> {
                        if (sectionName.isNotEmpty()) {
                            _sections.add(Section(sectionName, sectionInfo))
                        }
                        sectionName = line.replace(Regex("[^a-zA-Z0-9_]"), "")
                        sectionInfo.clear()
                    }
                    '=' -> {
                        if (line.length < 2 || line.split(' ')[1] != "=" || line.length < 3) {
                            throw IllegalArgumentException("Incorrect field string")
                        }
                        sectionInfo.add(line.split(' ')[0] + ' ' + line.split(' ')[2])
                    }
                    ']' -> {
                        if (line[0] != ';') throw IllegalArgumentException("Incorrect section string")
                    }
                    else -> {
                        throw IllegalArgumentException("Incorrect line format")
                    }
                }
            } else {
                if (line.isNotEmpty() && line[0] != ';') throw IllegalArgumentException("Incorrect section string")
            }
        }
        if (sectionName.isNotEmpty()) {
            _sections.add(Section(sectionName, sectionInfo))
        }
    }
    fun <T> get(sectionName: String, fieldName: String, type: Type): T {
        when (type) {
            Type.Cint -> {
                _sections.forEach {
                    if (it.sectionName == sectionName) {
                        return it.getField<Int>(fieldName, type) as T
                    }
                }
                throw ArrayIndexOutOfBoundsException("Section not found")
            }
            Type.Cfloat -> {
                _sections.forEach {
                    if (it.sectionName == sectionName) {
                        return it.getField<Float>(fieldName, type) as T
                    }
                }
                throw ArrayIndexOutOfBoundsException("Section not found")
            }
            Type.Cstring -> {
                _sections.forEach {
                    if (it.sectionName == sectionName) {
                        return it.getField<String>(fieldName, type) as T
                    }
                }
                throw ArrayIndexOutOfBoundsException("Section not found")
            }
        }
    }

    //Вложенный приватный класс для хранения секции
    private class Section(var sectionName: String, fields: List<String>) {
        private var _fields: MutableMap<String, String> = mutableMapOf()

        init {
            for (field in fields) {
                val parsedField = field.split(' ')
                _fields[parsedField[0]] = parsedField[1]
            }
        }

        fun <T>getField(fieldName: String, type: Type): T {
            if (!_fields.containsKey(fieldName)) {
                throw NoSuchFieldError("Field not found")
            } else {
                return when (type) {
                    Type.Cint -> {
                        when {
                            _fields[fieldName]!!.toIntOrNull() != null -> _fields[fieldName]?.toInt() as T
                            _fields[fieldName]!!.toFloatOrNull() != null -> {
                                val tempFieldValue = _fields[fieldName]?.toFloat()
                                if (tempFieldValue?.toInt()?.toFloat() == tempFieldValue) {
                                    tempFieldValue?.toInt() as T
                                } else {
                                    throw TypeCastException("Impossible type cast")
                                }
                            }
                            else -> throw TypeCastException("Impossible type cast")
                        }
                    }
                    Type.Cfloat -> {
                        if (_fields[fieldName]!!.toFloatOrNull() != null) _fields[fieldName]?.toFloat() as T
                        else throw TypeCastException("Impossible type cast")
                    }
                    Type.Cstring -> {
                        _fields[fieldName] as T
                    }
                }
            }
        }
    }
}