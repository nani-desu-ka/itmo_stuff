#include "../include/TeamLead.hpp"
#include "../include/Manager.hpp"

TeamLead::TeamLead(std::string name) : Employer(name, Manager::get()->hrManager.director) {}
void TeamLead::writeReport() {
//    TODO()
}


