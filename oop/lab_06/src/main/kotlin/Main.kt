import entities.Employer

fun main() {
    GlobalManager.newEmployer("Димоид Лещиков")
    GlobalManager.newTeamLead(GlobalManager.findEmployer("Димоид Лещиков"))
    GlobalManager.newEmployer("Димass Лещиков")
    GlobalManager.findEmployer("Димass Лещиков").master = GlobalManager.findEmployer("Димоид Лещиков")
    Employer(GlobalManager.findEmployer("Димass Лещиков")).createTask("Подимассить", "Подимассить")
    Employer(GlobalManager.findEmployer("Димass Лещиков")).activateTask(0)
    Employer(GlobalManager.findEmployer("Димass Лещиков")).closeTask(0)

    for (report in GlobalManager.runSprint(3)) {
        println("${report.Time} ${report._taskId} ${report.comment} ${report.employer.name}")
    }
}