package utils

class MasterNotSlave : Exception("Master is not a slave of his slave")
class SlaveDuplicate : Exception("Bruh")
class IncorrectFieldValue(comment: String) : Exception(comment)
class UnknownSelector : Exception("Unknown selector")
class ResponsibilityError : Exception("Employer not responsible for this task")
class EmptyChangeError : Exception("No changes found")
class TaskStateError : Exception("Task transformation error")
class MasterError : Exception("Master rights needed")
class EmployerError : Exception("Employer not found")