#pragma once

#include <list>
#include <vector>
#include "../../entities/include/Task.hpp"

class TaskManager {
public:
    void add_task(Task);
    Task &find_task_by_id(int);
    std::vector<Task> find_tasks_by_employer(Employer *);
    std::vector<Task> find_tasks_employer_edited(Employer *);
    std::vector<Task> find_tasks_by_create_time(std::string);
    std::vector<Task> find_tasks_by_change_time(std::string);
private:
    std::vector<Task> tasks; // хранилищще задач
};