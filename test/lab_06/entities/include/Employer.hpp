#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "Director.hpp"

class Employer {
public:
    Employer(std::string, Employer *);
    void add_vassal(Employer *);
    void remove_vassal(Employer *);
    std::vector<Employer> get_vassal_list();
    bool check_task(int);
    void create_task(std::string, std::string);
    void modify_task(int, std::string);
    virtual void writeReport() = 0;

    const std::string name;
    Employer *head;
protected:
    std::list<Employer *> vassals;
    std::vector<int> accessible_tasks;
};
