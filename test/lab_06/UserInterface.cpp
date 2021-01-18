#include "UserInterface.hpp"
#include "utils/CustomExceptions.hpp"

void UserInterface::hire_new_employer(std::string name, Employer *head) {
    if (name.empty()) throw EmployerException("Empty name");
    Manager::get()->hrManager.add_employer(new Employer(name, head));
}
void UserInterface::new_teamlead(Employer *employer) {
    if (employer->head != nullptr) {
        employer->head->remove_vassal(employer);
        employer->head = Manager::get()->hrManager.director;
    }
    Manager::get()->hrManager.director->add_vassal(employer);
}
void UserInterface::set_new_head(Employer *employer, Employer *new_head) {
    new_head->add_vassal(employer);
}
void UserInterface::fire_employer(Employer *employer) {
    Manager::get()->hrManager.remove_employer(employer);
}
Employer *UserInterface::find_employer(std::string name) {
    return Manager::get()->hrManager.get_employer_by_name(name);
}
std::vector<Task> UserInterface::find_tasks(std::string value, Selector selector) {
    switch (selector) {
        case TIME_CREATE:
            return Manager::get()->taskManager.find_tasks_by_create_time(value);
        case TIME_CHANGE:
            return Manager::get()->taskManager.find_tasks_by_change_time(value);
        default:
            throw SelectorException("TIME_CREATE || TIME_CHANGE only");
    }
}
Task &UserInterface::find_task(int id) {
    return Manager::get()->taskManager.find_task_by_id(id);
}
std::vector<Task> UserInterface::find_tasks(Employer *employer, Selector selector) {
    switch (selector) {
        case EMPLOYER:
            return Manager::get()->taskManager.find_tasks_by_employer(employer);
        case EMPLOYER_TOUCHED:
            return Manager::get()->taskManager.find_tasks_employer_edited(employer);
        default:
            throw SelectorException("EMPLOYER || EMPLOYER_TOUCHED only");
    }
}

void UserInterface::start_sprint() {
    for (auto employer : Manager::get()->hrManager.employers) {
        employer->clean_reports();
    }
    sprint_active = true;
}

void UserInterface::end_day() {
    for (auto employer : Manager::get()->hrManager.employers) {
        employer->write_report();
    }
}

std::vector<TotalSprintReport> UserInterface::end_sprint() {
    sprint_active = false;
    return Manager::get()->hrManager.director->get_sprint();
}

void UserInterface::print_ierarchy() {
    Manager::get()->hrManager.director->print_ierarchy(0);
}