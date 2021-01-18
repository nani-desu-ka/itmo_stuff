#include "../include/Employer.hpp"
#include "../../utils/CustomExceptions.hpp"
#include "../include/Manager.hpp"

Employer::Employer(std::string name, Employer *head) : name(name), head(head) {}

void Employer::add_vassal(Employer *new_vassal) {
    if (new_vassal == head) throw EmployerException("Head can't be vassal");
    for (auto vassal : vassals) {
        if (vassal == new_vassal) throw EmployerException("Vassal duplication");
    }
    new_vassal->head = this;
    vassals.push_back(new_vassal);
}

void Employer::remove_vassal(Employer *vassal) {
    for (auto temp_vassal : vassals) {
        if (temp_vassal == vassal)  {
            vassals.remove(vassal);
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

void Employer::create_task(std::string name, std::string description = "") {
    Manager::get()->taskManager.add_task(Task(name, description, this));
}

void Employer::modify_task(int id, std::string change) {
    if (!check_task(id)) throw TaskException("Unacceptable task");
    Manager::get()->taskManager.find_task_by_id(id).task_modification(change);
}