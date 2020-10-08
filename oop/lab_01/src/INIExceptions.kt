class UncastableFieldError(fieldName: String?, typeName: String) : Exception("Cant cast $fieldName to $typeName")
class NoFieldExceptionError(fieldName: String?) : Exception("$fieldName not found")
class IllegalLineFormat(message: String) : Exception(message)