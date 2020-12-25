#pragma once

#include <iostream>
#include "Employer.hpp"
#include "../../utils/Enums.hpp"

class Task {
public:
    Task(std::string, std::string, Employer *);
    TaskState task_state = OPEN; //состояние задачи
    std::string name;
    std::string description;
    std::string create_time;
    std::string last_change_time;
    bool modified = false;
    Employer *responsible_employer;
    void task_modification(std::string); //модификация задачи
};
