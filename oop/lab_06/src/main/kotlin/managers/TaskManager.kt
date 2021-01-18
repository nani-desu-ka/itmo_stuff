package managers

import entities.Employer
import entities.EmployerData
import entities.Task
import utils.TaskState

class TaskManager {
    val tasks: MutableList<Task> = mutableListOf()
    fun findTaskID(id: Int): Task {
        return tasks[id]
    }
    fun findTaskEmployerMaster(master: EmployerData): List<Pair<Task, Int>> {
        val outputTasks: MutableList<Pair<Task, Int>> = mutableListOf()
        for (i in 0 until tasks.size) {
            if (master == tasks[i].responsibleEmployer) {
                outputTasks.add(Pair(tasks[i], i))
            }
        }
        return outputTasks
    }
    fun findTaskEmployerChanges(master: EmployerData): List<Task> {
        val outputTasks: MutableList<Task> = mutableListOf()
        for (i in 0 until tasks.size) {
            if (master == tasks[i].responsibleEmployer && tasks[i].state == TaskState.ACTIVE) {
                outputTasks.add(tasks[i])
            }
        }
        return outputTasks
    }
    fun createTask(name: String, master: EmployerData, description: String = ""): Int {
        tasks.add(Task(name, master, description))
        return tasks.lastIndex
    }
}