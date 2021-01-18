#pragma once

#include "../../entities/include/Employer.hpp"
#include <list>

class HRManager { // менеджер работников
public:
    Employer *director = new Employer(); // самый главный на предприятии, у него в подчинении все тимлиды
    void add_employer(Employer *);
    void remove_employer(Employer *);
    Employer *get_employer_by_name(std::string);
    std::vector<Employer *> employers; // хранилище сотрудников
};