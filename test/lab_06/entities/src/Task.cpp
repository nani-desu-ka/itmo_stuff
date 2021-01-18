#include "../include/Task.hpp"
#include "../../utils/CustomExceptions.hpp"
#include "../../utils/TimeChecker.hpp"

Task::Task(std::string name, std::string description, Employer *responsible_employer) : name(name),
description(description), responsible_employer(responsible_employer) {
    create_time = TimeChecker::get_time();
    last_change_time = TimeChecker::get_time();
}

void Task::task_modification(std::string new_description) {
    if (task_state != ACTIVE) throw TaskException("Cant modify INACTIVE task");
    description = new_description;
    modified = true;
    last_change_time = TimeChecker::get_time();
}

void Task::activate_task() {
    if (task_state != OPEN) throw TaskException( "Task cant be activated");
    task_state = ACTIVE;
    last_change_time = TimeChecker::get_time();
}

void Task::resolve_task() {
    if (task_state != ACTIVE) throw TaskException("Task cant be resolved");
    task_state = RESOLVED;
    last_change_time = TimeChecker::get_time();
}