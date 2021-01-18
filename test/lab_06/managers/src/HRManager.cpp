#include "../include/HRManager.hpp"
#include "../../utils/CustomExceptions.hpp"

void HRManager::add_employer(Employer *employer) {
    employers.push_back(employer);
}
void HRManager::remove_employer(Employer *employer) {
    for (int i = 0; i < employers.size(); i++) {
        if (employers[i] == employer) employers.erase(employers.begin() + i);
    }
}
Employer *HRManager::get_employer_by_name(std::string name) {
    for (auto employer : employers) {
        if (employer->name == name) {
            return employer;
        }
    }
    throw EmployerException("Cant find employer");
}