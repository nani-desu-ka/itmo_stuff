import java.io.File
import java.io.FileNotFoundException

enum class Type {
    Cint,
    Cfloat,
    Cstring,
}

@Suppress("UNCHECKED_CAST")
class INIBuilder(fileName: String) {
    private var _inputFile = File(fileName)
    private val _sections = ArrayList<Section>()
    init {
        if (!_inputFile.exists()) {
            throw FileNotFoundException("File not found")
        }
        if (_inputFile.extension != "INI") {
            throw FileNotFoundException("Incorrect file extension")
        }
        val inputStream = _inputFile.inputStream()
        val text = inputStream.bufferedReader().readLines()
        var sectionName = ""
        val sectionInfo = ArrayList<String>()
        for (line in text) {
            if (line.replace(Regex("[^\\[=\\];]+"), "").isNotEmpty()) {
                when (line.replace(Regex("[^\\[=\\];]+"), "")[0]) {
                    '[' -> {
                        if (line[0] != '[') throw IllegalArgumentException("Incorrect section line format\n" +
                                line)
                        if (sectionName.isNotEmpty()) {
                            _sections.add(Section(sectionName, sectionInfo))
                        }
                        sectionName = ""
                        var i = 1
                        while (line[i] != ']') {
                            if(line[i] == ';') throw IllegalArgumentException("Incorrect section line format\n" +
                                    line)
                            sectionName += line[i]
                            i++
                            if (i >= line.length) {
                                throw ArrayIndexOutOfBoundsException("Incorrect section line format\n$line")
                            }
                        }
                        sectionInfo.clear()
                    }
                    '=' -> {
                        if (sectionName.isEmpty()) throw IllegalArgumentException("Incorrect field line format " +
                                "(blank section name)")
                        if (line.split(' ').size < 2 || line.split(' ')[1] != "=" ||
                                line.split(' ').size < 3 || line.split(' ')[2][0] == ';') {
                            throw IllegalArgumentException("Incorrect field line format\n$line")
                        }
                        if (line.split(' ').size > 3 && line.split(' ')[3] != ";") {
                            throw IllegalArgumentException("Incorrect field line format\n$line")
                        }
                        sectionInfo.add(line.split(' ')[0] + ' ' + line.split(' ')[2])
                    }
                    ';' -> {
                        if (line[0] != ';') throw IllegalArgumentException("Incorrect comment line format\n" +
                                line)
                        continue
                    }
                    else -> {
                        throw IllegalArgumentException("Incorrect line format\n$line")
                    }
                }
            } else {
                if (line.isNotEmpty() && line[0] != ';') {
                    throw IllegalArgumentException("Incorrect section line format\n$line")
                }
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
                throw ArrayIndexOutOfBoundsException("Section not found\n$sectionName")
            }
            Type.Cfloat -> {
                _sections.forEach {
                    if (it.sectionName == sectionName) {
                        return it.getField<Float>(fieldName, type) as T
                    }
                }
                throw ArrayIndexOutOfBoundsException("Section not found\n$sectionName")
            }
            Type.Cstring -> {
                _sections.forEach {
                    if (it.sectionName == sectionName) {
                        return it.getField<String>(fieldName, type) as T
                    }
                }
                throw ArrayIndexOutOfBoundsException("Section not found\n$sectionName")
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
                throw NoSuchFieldError("Field not found\n$fieldName")
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
                                    throw TypeCastException("Impossible type cast\n$type")
                                }
                            }
                            else -> throw TypeCastException("Impossible type cast\n$type")
                        }
                    }
                    Type.Cfloat -> {
                        if (_fields[fieldName]!!.toFloatOrNull() != null) _fields[fieldName]?.toFloat() as T
                        else throw TypeCastException("Impossible type cast\n$type")
                    }
                    Type.Cstring -> {
                        _fields[fieldName] as T
                    }
                }
            }
        }
    }
}