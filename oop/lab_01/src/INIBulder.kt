import java.io.File
import java.io.FileNotFoundException

@Suppress("UNCHECKED_CAST")
class INIBuilder(fileName: String) {
    private var _inputFile = File(fileName)
    private val _sections = ArrayList<Section>()
    init {
        if (!_inputFile.exists()) {
            throw FileNotFoundException("File not found")
        }
        if (_inputFile.extension.toLowerCase() != "ini") {
            throw FileNotFoundException("Incorrect file extension")
        }
        val inputStream = _inputFile.inputStream()
        val text = inputStream.bufferedReader().readLines()
        var sectionName = ""
        val sectionInfo = ArrayList<String>()
        for (line in text) {
            val specialSymbols = line.replace(Regex("[^\\[=\\];]+"), "")
            if (specialSymbols.isNotEmpty()) {
                when (specialSymbols[0]) {
                    '[' -> {
                        if (line[0] != '[') throw IllegalLineFormat("Incorrect section line format\n" +
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
                        val formattedLine = line.replace(" ", "")
                        if (sectionName.isEmpty()) throw IllegalLineFormat("Incorrect field line format " +
                                "(blank section name)")
                        var tempFieldName = ""
                        var tempFieldValue = ""
                        var iter = 0
                        while (formattedLine[iter] != '=') {
                            tempFieldName += formattedLine[iter++]
                        }
                        if (iter == 0) throw IllegalLineFormat("Incorrect field name format")
                        while (++iter != formattedLine.length && formattedLine[iter] != ';') {
                            tempFieldValue += formattedLine[iter]
                        }
                        sectionInfo.add("$tempFieldName $tempFieldValue")
                    }
                    ';' -> {
                        if (line[0] != ';') throw IllegalLineFormat("Incorrect comment line format\n" +
                                line)
                        continue
                    }
                    else -> {
                        throw IllegalLineFormat("Incorrect line format\n$line")
                    }
                }
            } else {
                if (line.isNotEmpty() && line[0] != ';') {
                    throw IllegalLineFormat("Incorrect section line format\n$line")
                }
            }
        }
        if (sectionName.isNotEmpty()) {
            _sections.add(Section(sectionName, sectionInfo))
        }
    }

    fun getInt(sectionName: String, fieldName: String): Int {
        _sections.forEach {
            if (it.sectionName == sectionName) {
                return it.getIntField(fieldName)
            }
        }
        throw ArrayIndexOutOfBoundsException("Section not found\n$sectionName")
    }
    fun getFloat(sectionName: String, fieldName: String): Float {
            _sections.forEach {
                if (it.sectionName == sectionName) {
                    return it.getFloatField(fieldName)
                }
            }
            throw ArrayIndexOutOfBoundsException("Section not found\n$sectionName")
        }
    fun getString(sectionName: String, fieldName: String): String {
            _sections.forEach {
                if (it.sectionName == sectionName) {
                    return it.getStringField(fieldName)
                }
            }
            throw ArrayIndexOutOfBoundsException("Section not found\n$sectionName")
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
        fun getIntField(fieldName: String): Int {
            if (!_fields.containsKey(fieldName)) throw NoFieldExceptionError(fieldName)
            return when {
                _fields[fieldName]!!.toIntOrNull() != null -> _fields[fieldName]!!.toInt()
                _fields[fieldName]!!.toFloatOrNull() != null -> {
                    val tempFieldValue = _fields[fieldName]?.toFloat()
                    if (tempFieldValue?.toInt()?.toFloat() == tempFieldValue) {
                        tempFieldValue!!.toInt()
                    } else {
                        throw UncastableFieldError(fieldName, "Float")
                    }
                }
                else -> throw UncastableFieldError(fieldName, "Float")
            }
        }
        fun getFloatField(fieldName: String): Float {
            if (!_fields.containsKey(fieldName)) throw NoFieldExceptionError(fieldName)
            if (_fields[fieldName]!!.toFloatOrNull() != null) {
                return _fields[fieldName]!!.toFloat()
            } else {
                throw UncastableFieldError(fieldName, "Float")
            }
        }
        fun getStringField(fieldName: String): String {
            if (!_fields.containsKey(fieldName)) throw NoFieldExceptionError(fieldName)
            return _fields[fieldName]!!
        }
    }
}