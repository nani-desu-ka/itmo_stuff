package managers

object Storage {
    val taskManager: TaskManager = TaskManager()
    val director: Director = Director()
    val reportManager: ReportManager = ReportManager()
    val changeListManager: ChangeListManager = ChangeListManager()
}