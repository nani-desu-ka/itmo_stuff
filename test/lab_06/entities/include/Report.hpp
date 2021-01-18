#pragma once

#include "../../utils/Enums.hpp"
#include "iostream"

class Report {
public:
    Report(int, ChangeType, std::string);
    int get_task_id();
    std::string get_time();
    ChangeType get_change_type();
private:
    int task_id;
    ChangeType task_state_change;
    std::string time;
};