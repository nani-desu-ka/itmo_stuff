package entities

import utils.*

open class Employer(val name: String) {
    private val buffLayerConnector = BuffLayer()
    var master: EmployerData? = null
    private var slaves: MutableList<EmployerData> = mutableListOf()
    private var taskIDs: MutableList<Int> = mutableListOf()
    private var dayReport = FinalDayReport()
    private var sprintReports: MutableList<FinalDayReport> = mutableListOf()
    private var tempReport: String = ""
    init {
        if (name != "empty") {
            master = EmployerData("empty")
        }
    }
    constructor(employer: EmployerData) : this(employer.name) {
                    slaves = employer.slaves
                    taskIDs = employer.taskIDs
                    dayReport = employer.dayReport
                    master = employer.master
                    sprintReports = employer.sprintReports
                    tempReport = employer.tempReport
                }
    fun addSlave(newSlave: EmployerData) {
        if (newSlave == master) {
            throw MasterNotSlave()
        }
        for (slave in slaves) {
            if (slave == newSlave) {
                throw SlaveDuplicate()
            }
        }
        newSlave.master = buffLayerConnector.findEmployer(this)
        slaves.add(newSlave)
        saveState()
    }
    fun removeSlave(slave: EmployerData) {
        slaves.remove(slave)
        saveState()
    }
    fun getSlaves(): List<EmployerData> {
        val slaveList: MutableList<EmployerData> = mutableListOf()
        for (slave in slaves) {
            slaveList.addAll(Employer(slave).getSlaves())
        }
        return slaveList
    }
    fun createTask(name: String, description: String = "") {
        val id = buffLayerConnector.taskCreator(name, this, description)
        taskIDs.add(id)
        val currentTime = StaticMethods.timeGetter()
        buffLayerConnector.addCreation(currentTime, id)
        dayReport.add(Report(id, currentTime, "Task opened", this))
        saveState()
    }
    fun removeResolvedTasks() {
        for (i in 0 until taskIDs.size) {
            if (buffLayerConnector.getTaskState(taskIDs[i]) == TaskState.RESOLVED) {
                val name = buffLayerConnector.findTaskName(taskIDs[i])
                taskIDs.remove(taskIDs[i])
                val currentTime = StaticMethods.timeGetter()
                buffLayerConnector.addRemoval(currentTime, taskIDs[i])
            }
        }
        saveState()
    }
    private fun findAllOwnTasks(): List<Pair<Task, Int>> {
        return buffLayerConnector.findTaskEmployerMaster(this)
    }
    fun getTask(taskID: Int): Task {
        for (taskAndId in findAllOwnTasks()) {
            if (taskAndId.second == taskID) return taskAndId.first
        }
        throw ResponsibilityError()
    }
    fun activateTask(taskID: Int) {
        val task = getTask(taskID)
        if (task.state != TaskState.OPEN) throw TaskStateError()
        task.state = TaskState.ACTIVE
        val currentTime = StaticMethods.timeGetter()
        buffLayerConnector.addActivasion(currentTime, taskID)
    }
    fun closeTask(taskID: Int) {
        val task = getTask(taskID)
        if (task.state != TaskState.ACTIVE) throw TaskStateError()
        task.state = TaskState.RESOLVED
        val currentTime = StaticMethods.timeGetter()
        val name = buffLayerConnector.findTaskName(taskID)
        buffLayerConnector.addResolving(currentTime, taskID)
        dayReport.add(Report(taskID, currentTime, "Task closed", this))
        saveState()
    }
    fun modifyTask(taskID: Int, modification: String) {
        val task = getTask(taskID)
        task.modifyTask(modification)
        val currentTime = StaticMethods.timeGetter()
        buffLayerConnector.addModification(currentTime, taskID)
    }
    fun writeReport() {
        sprintReports.add(dayReport)
        dayReport = FinalDayReport()
    }
    fun writeSprintReport() {
        for (report in sprintReports) {
            buffLayerConnector.addFinalDayReport(report)
        }
        sprintReports.clear()
    }
    fun compileTotalSprintReport(): MutableList<Report> {
        val outputReport: MutableList<Report> = mutableListOf()
        if (this.master == null && buffLayerConnector.getDirectorTeamLead() != buffLayerConnector.findEmployer(this)) {
            throw MasterError()
        }
        if (master?.name == "empty") {
            throw MasterError()
        }
        for (sprintReport in buffLayerConnector.getSprintReports()) {
            for (comment in sprintReport.reports) {
                outputReport.add(comment)
            }
        }
        buffLayerConnector.clearReports()
        return outputReport
    }
    fun saveState() {
        val data = buffLayerConnector.findEmployer(this)
        data.master = master
//        data.taskIDs = taskIDs
//        data.slaves = slaves
        data.dayReport = dayReport
//        data.sprintReports = sprintReports
        data.tempReport = tempReport
    }
}