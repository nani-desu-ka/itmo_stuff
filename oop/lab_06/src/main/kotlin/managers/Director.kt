package managers

import entities.EmployerData
import utils.EmployerError

class Director {
    var teamLead: EmployerData = EmployerData("empty")
    val employers: MutableList<EmployerData> = mutableListOf()
    fun newEmployer(newEmployer: EmployerData) {
        employers.add(newEmployer)  
    }
    fun fireEmployer(employer: EmployerData) {
        employers.remove(employer)
    }
    fun getEmployer(name: String): EmployerData {
        for (employer in Storage.director.employers) {
            if (employer.name == name) {
                return employer
            }
        }
        throw EmployerError()
    }
}