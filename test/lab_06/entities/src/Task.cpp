#include "../include/Task.hpp"

Task::Task(std::string name, std::string description, Employer *responsible_employer) : name(name),
description(description), responsible_employer(responsible_employer) {
//    create_time =
}

void Task::task_modification(std::string new_description) {
    description = new_description;
    modified = true;
}
