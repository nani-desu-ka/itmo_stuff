#include "UserInterface.hpp"
#include "entities/include/TeamLead.hpp"
#include "entities/include/Rabotyaga.hpp"
#include "utils/CustomExceptions.hpp"

void UserInterface::hire_new_employer(std::string name, Employer *head = nullptr) {
    if (name.empty()) throw EmployerException("Empty name");
    Manager::get()->hrManager.add_employer(new Rabotyaga(name, head));
}
void UserInterface::set_new_teamlead(Employer *employer) {
    if (employer->head != nullptr) {
        employer->head->remove_vassal(employer);
        employer->head = Manager::get()->hrManager.director;
    }
    Manager::get()->hrManager.director->head;
    Manager::get()->hrManager.director->add_vassal(employer);
    Manager::get()->hrManager.director->add_vassal(employer);
}
void UserInterface::set_new_head(Employer *employer, Employer *new_head) {
    if (employer->head != nullptr) employer->head->remove_vassal(employer);
    employer->head = new_head;
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