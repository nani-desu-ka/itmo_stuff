package entities

import managers.Storage
import utils.TaskState

class BuffLayer {
    fun findEmployer(employer: Employer): EmployerData {
        return Storage.director.getEmployer(employer.name)
    }
    fun findTaskName(taskID: Int): String {
        return Storage.taskManager.findTaskID(taskID).name
    }
    fun addModification(currentTime: String, taskID: Int) {
        Storage.changeListManager.addChange(currentTime, "($currentTime) Task modified: $taskID")
    }
    fun addCreation(currentTime: String, taskID: Int) {
        Storage.changeListManager.addChange(currentTime, "($currentTime) Task opened: $taskID")
    }
    fun addResolving(currentTime: String, taskID: Int) {
        Storage.changeListManager.addChange(currentTime, "($currentTime) Task resolved: $taskID")
    }
    fun addRemoval(currentTime: String, taskID: Int) {
        Storage.changeListManager.addChange(currentTime, "($currentTime) Resolved task removed: $taskID")
    }
    fun addActivasion(currentTime: String, taskID: Int) {
        Storage.changeListManager.addChange(currentTime, "($currentTime) Task activated: $taskID")
    }
    fun addFinalDayReport(report: FinalDayReport) {
        Storage.reportManager.sprintReports.add(report)
    }
    fun clearReports() {
        Storage.reportManager.sprintReports.clear()
    }
    fun findTaskEmployerMaster(employer: Employer): List<Pair<Task, Int>> {
        return Storage.taskManager.findTaskEmployerMaster(findEmployer(employer))
    }
    fun taskCreator(name: String, employer: Employer, description: String): Int {
        return Storage.taskManager.createTask(name, findEmployer(employer), description)
    }
    fun getSprintReports(): List<FinalDayReport> {
        return Storage.reportManager.sprintReports
    }
    fun getTaskState(id: Int): TaskState {
        return Storage.taskManager.tasks[id].state
    }
    fun getDirectorTeamLead(): EmployerData {
        return Storage.director.teamLead
    }
}