fun main() {
    println("|==INI parser application==|")
    print("Enter INI input file name: ")
    val fileName = readLine()
    if (fileName.isNullOrEmpty()) {
        println("Empty input")
        return
    }
    val test: INIBuilder
    try {
        test = INIBuilder(fileName)
    } catch (e: Exception) {
        println(e)
        return
    }

    var active = true
    while (active) {
        print("Enter section name: ")
        val sectionName = readLine()
        if (sectionName.isNullOrEmpty()) {
            println("Empty input")
            return
        }
        print("Enter field name: ")
        val fieldName = readLine()
        if (fieldName.isNullOrEmpty()) {
            println("Empty input")
            return
        }
        print("Enter type: ")
        try {
            when (readLine()) {
                "int" -> {
                    val output = test.get<Int>(sectionName, fieldName, Type.Cint)
                    println("$output\n")
                }
                "float" -> {
                    val output = test.get<Float>(sectionName, fieldName, Type.Cfloat)
                    println("$output\n")
                }
                "string" -> {
                    val output = test.get<String>(sectionName, fieldName, Type.Cstring)
                    println("$output\n")
                }
                else -> {
                    println("Incorrect type name")
                    return
                }
            }
        } catch (e: Exception) {
            println(e)
            return
        }
        print("Continue? (Y/N)\n->")
        active = when (readLine()) {
            "Y", "y" -> true
            "N", "n" -> false
            else -> {
                println("Incorrect input")
                return
            }
        }
    }
}