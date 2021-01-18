#include "../include/TaskManager.hpp"
#include "../../utils/CustomExceptions.hpp"

Task &TaskManager::find_task_by_id(int id) {
    if (id >= tasks.size()) throw TaskException("Task ID out of range");
    return tasks[id];
}
std::vector<Task> TaskManager::find_tasks_by_employer(Employer *employer) {
    std::vector<Task> output;
    for (auto &task : tasks) {
        if (task.responsible_employer == employer) output.push_back(task);
    }
    return output;
}

std::vector<Task> TaskManager::find_tasks_by_create_time(std::string time) {
    std::vector<Task> output;
    for (auto &task : tasks) {
        if (task.create_time == time) output.push_back(task);
    }
    return output;
}
std::vector<Task> TaskManager::find_tasks_by_change_time(std::string time) {
    std::vector<Task> output;
    for (auto &task : tasks) {
        if (task.last_change_time == time) output.push_back(task);
    }
    return output;
}
std::vector<Task> TaskManager::find_tasks_employer_edited(Employer *employer) {
    std::vector<Task> output;
    for (auto &task : tasks) {
        if (task.responsible_employer == employer && task.modified) output.push_back(task);
    }
    return output;
}
void TaskManager::add_task(Task task) {
    tasks.push_back(task);
}