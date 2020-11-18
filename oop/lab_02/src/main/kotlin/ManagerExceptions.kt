class SameIdEntityException(entity: Int) : Exception("$entity is already created")
class UnknownEntityException(entity: String) : Exception("$entity not found")
class UnableToBuyException : Exception("Wrong order")