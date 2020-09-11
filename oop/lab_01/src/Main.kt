fun main() {
    val mem: String
    try {
        val test = INIBuilder("test.INI")
        mem = test.get("COMMON", "DiskCachePath", Type.Cstring)
    } catch (e: Exception) {
        println(e)
        return
    }
    println(mem)
}