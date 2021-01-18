#include "../include/Report.hpp"

Report::Report(int id, ChangeType change_type, std::string task_time) : task_id(id), task_state_change(change_type), time(task_time) {}

int Report::get_task_id() {
    return task_id;
}

ChangeType Report::get_change_type() {
    return task_state_change;
}

std::string Report::get_time() {
    return time;
}