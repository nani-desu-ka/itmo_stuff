import entities.*
import managers.Storage
import utils.*

object GlobalManager {
    fun newTeamLead(employer: EmployerData): GlobalManager {
        if (Storage.director.teamLead.master != null) {
            Employer(employer).addSlave(Storage.director.teamLead.master!!)
        }
        Storage.director.teamLead.master = employer
        return this
    }
    fun newEmployer(name: String) {
        if (name.toLowerCase() == "empty") {
            throw IncorrectFieldValue("Incorrect employer name")
        }
        Storage.director.newEmployer(EmployerData(name))
    }
    fun setNewMaster(slave: EmployerData, newMaster: EmployerData): GlobalManager {
        Employer(slave).removeSlave(slave)
        Employer(newMaster).addSlave(slave)
        return this
    }
    fun fireEmployer(employer: EmployerData) {
        for (slave in Employer(employer).getSlaves()) {
            setNewMaster(slave, employer.master!!)
        }
        Employer(employer.master!!).removeSlave(employer)
        Storage.director.fireEmployer(employer)
    }
    fun findEmployer(name: String): EmployerData {
        return Storage.director.getEmployer(name)
    }
    fun findTask(value: String, selector: FindMode): List<Task> {
        return when (selector) {
            FindMode.ID -> listOf(Storage.taskManager.findTaskID(value.toInt()))
            FindMode.EMPLOYER -> Storage.taskManager.findTaskEmployerMaster(findEmployer(value)).unzip().first
            FindMode.EMPLOYERCHANGES -> Storage.taskManager.findTaskEmployerChanges(findEmployer(value))
            else -> throw UnknownSelector()
        }
    }
    private fun runDay() {
        for (employer in Storage.director.employers) {
            Employer(employer).writeReport()
            Employer(employer).removeResolvedTasks()
        }
    }
    fun runSprint(dayAmount: Int): MutableList<Report> {
        for (i in 0 until dayAmount) {
            runDay()
        }
        for (employer in Storage.director.employers) {
            Employer(employer).writeSprintReport()
        }
        return Employer(Storage.director.teamLead).compileTotalSprintReport()
    }
}