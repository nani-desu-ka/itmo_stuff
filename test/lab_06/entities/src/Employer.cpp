#include "../include/Employer.hpp"
#include "../../utils/CustomExceptions.hpp"
#include "../include/Manager.hpp"
#include "../../utils/TimeChecker.hpp"

Employer::Employer() : name("Director"), head(nullptr) {}

Employer::Employer(std::string name, Employer *head) : name(name), head(head) {}

void Employer::add_vassal(Employer *new_vassal) {
    if (new_vassal == head) throw EmployerException("Head can't be vassal");
    for (auto vassal : vassals) {
        if (vassal == new_vassal) throw EmployerException("Vassal duplication");
    }
    new_vassal->head = this;
    vassals.push_back(new_vassal);
    std::string time = TimeChecker::get_time();
    Manager::get()->logManager.add_log_note(time, "Vassal removed: " + new_vassal->name);
}

void Employer::remove_vassal(Employer *vassal) {
    for (auto temp_vassal : vassals) {
        if (temp_vassal == vassal)  {
            vassals.remove(vassal);
            std::string time = TimeChecker::get_time();
            Manager::get()->logManager.add_log_note(time, "Vassal removed: " + vassal->name);
            return;
        }
    }
    throw EmployerException("Cant remove vassal which is not vassal");
}

bool Employer::check_task(int id) {
    for (auto _id : accessible_tasks) {
        if (_id == id) return true;
    }
    return false;
}

int Employer::create_task(std::string name, std::string description) {
    int id = Manager::get()->taskManager.add_task(Task(name, description, this));
    accessible_tasks.push_back(id);
    std::string time = TimeChecker::get_time();
    Manager::get()->logManager.add_log_note(time, "New task: " + name);
    day_reports.add(Report(id, OPENED_TASK, time));
    return id;
}

void Employer::modify_task(int id, std::string change) {
    if (!check_task(id)) throw TaskException("Unacceptable task");
    Manager::get()->taskManager.find_task_by_id(id).task_modification(change);
    std::string time = TimeChecker::get_time();
    Manager::get()->logManager.add_log_note(time, "Task modified: " + name);
    day_reports.add(Report(id, MODIFIED_TASK, time));
}

void Employer::activate_task(int id) {
    if (!check_task(id)) throw TaskException("Unacceptable task");
    Manager::get()->taskManager.find_task_by_id(id).activate_task();
    std::string time = TimeChecker::get_time();
    Manager::get()->logManager.add_log_note(time, "Task activated: " + name);
    day_reports.add(Report(id, ACTIVATED_TASK, time));
}

void Employer::resolve_task(int id) {
    if (!check_task(id)) throw TaskException("Unacceptable task");
    Manager::get()->taskManager.find_task_by_id(id).resolve_task();
    std::string time = TimeChecker::get_time();
    Manager::get()->logManager.add_log_note(time, "Task resolved: " + name);
    day_reports.add(Report(id, RESOLVED_TASK, time));
}

std::vector<int> Employer::check_resolved_tasks() {
    std::vector<int> output;
    for (auto id : accessible_tasks) {
        if (Manager::get()->taskManager.find_task_by_id(id).task_state == RESOLVED) output.push_back(id);
    }
    return output;
}

void Employer::write_report() {
    sprint_reports.add(day_reports);
    day_reports = TotalDayReport();
}

std::vector<TotalSprintReport> Employer::write_sprint() {
    std::vector<TotalSprintReport> output;
    output.push_back(sprint_reports);
    for (auto vassal : vassals) {
        for (auto report : vassal->write_sprint()) {
            output.push_back(report);
        }
    }
    std::cout << '\n';
    return output;
}

TotalSprintReport Employer::compile_sprint() {
    for (auto vassal : vassals) {
        for (auto &sprint_report : vassal->write_sprint()) {
            for (auto &report : sprint_report.sprint_reports) {
                sprint_reports.add(report);
            }
        }
    }
    return sprint_reports;
}

std::vector<TotalSprintReport> Employer::get_sprint() {
    std::vector<TotalSprintReport> output;
    for (auto teamlead : vassals) {
        output.push_back(teamlead->compile_sprint());
    }
    return output;
}

void Employer::clean_reports() {
    day_reports = TotalDayReport();
    sprint_reports = TotalSprintReport();
}

void Employer::print_ierarchy(int level) {
    std::cout << '\n';
    for (int i = 0; i < level; i++) {
        std::cout << ' ';
    }
    std::cout << name;
    for (auto vassal : vassals) {
        vassal->print_ierarchy(level + 1);
    }
}