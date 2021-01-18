package entities

import utils.TaskState

class Task(val name: String, var responsibleEmployer: EmployerData, taskDescription: String = "") {
    var state: TaskState = TaskState.OPEN
    var description = taskDescription
    fun modifyTask(modification: String) {
        description = modification
    }
}