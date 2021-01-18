#pragma once

#include "iostream"
#include "entities/include/Employer.hpp"
#include "utils/Enums.hpp"
#include "entities/include/Manager.hpp"
#include "entities/include/Task.hpp"

class UserInterface { // верхний уровень, где пользователь взаимодействует с программой
public:
//    UserInterface() = default;
    void hire_new_employer(std::string, Employer * = nullptr); //нанять работника
    void new_teamlead(Employer *); //сделать сотрудника тимлидом
    void set_new_head(Employer *, Employer *); //сделать сотрудника начальником другого сотрудника
    void fire_employer(Employer *); //увольнение
    Employer *find_employer(std::string); //поиск работника по его имени
    std::vector<Task> find_tasks(std::string, Selector); //поиск задач по времени
    Task &find_task(int); //поиск задач по ID
    std::vector<Task> find_tasks(Employer *, Selector); //поиск задач по работнику
    void end_day(); //заканчивает день и заставляет всех работников писать ежедневный репорт
    void start_sprint(); //начинает спринт
    std::vector<TotalSprintReport> end_sprint(); //заканчивает спринт
    void print_ierarchy(); //печатает иерархию (зависимость понятна по отступам)
private:
    bool sprint_active = false;
};