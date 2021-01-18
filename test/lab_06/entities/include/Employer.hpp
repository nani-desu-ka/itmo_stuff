#pragma once

#include <iostream>
#include <vector>
#include <list>
#include "TotalDayReport.hpp"
#include "TotalSprintReport.hpp"

class Employer {
public:
    Employer();
    Employer(std::string, Employer *);
    void add_vassal(Employer *);
    void remove_vassal(Employer *);
    void print_ierarchy(int);
    bool check_task(int);
    int create_task(std::string, std::string = ""); //создать таску (возвращает id таски для более удобной работы)
    void activate_task(int); //активировать таску
    void resolve_task(int); //закрыть таску
    void modify_task(int, std::string); //изменить описание
    std::vector<int> check_resolved_tasks();
    void write_report();
    void clean_reports();
    std::vector<TotalSprintReport> write_sprint(); //рабочие получают отчеты от своих подчиненных (метод использует только работяга начальник)
    TotalSprintReport compile_sprint(); //тимлиды собирают все репорты в один (метод использует только тимлид)
    std::vector<TotalSprintReport> get_sprint(); //директор получает спринт репорты от всех тимлидов (метод использует только директор)

    const std::string name;
    Employer *head;
protected:
    std::list<Employer *> vassals;
    std::vector<int> accessible_tasks;
    TotalDayReport day_reports;
    TotalSprintReport sprint_reports;
};
