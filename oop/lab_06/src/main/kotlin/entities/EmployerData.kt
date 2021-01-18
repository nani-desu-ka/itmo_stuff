package entities

class EmployerData(val name: String) {
    constructor(employer: Employer) : this(employer.name) {
        master = employer.master
    }
    val buffLayerConnector = BuffLayer()
    var master: EmployerData? = null
    var slaves: MutableList<EmployerData> = mutableListOf()
    var taskIDs: MutableList<Int> = mutableListOf()
    var dayReport = FinalDayReport()
    var sprintReports: MutableList<FinalDayReport> = mutableListOf()
    var tempReport: String = ""
    init {
        if (name != "empty") {
            master = EmployerData("empty")
        }
    }
}