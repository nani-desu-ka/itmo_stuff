package utils

import java.time.LocalDateTime
import java.time.format.DateTimeFormatter

object StaticMethods {
    fun timeGetter(): String {
        val current = LocalDateTime.now()
        val formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss.SSS")
        val formatted = current.format(formatter)
        return formatted
    }
}