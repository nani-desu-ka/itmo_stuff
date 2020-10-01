import java.io.File
import java.io.FileNotFoundException
import kotlin.reflect.typeOf

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
            
        }
    }
}