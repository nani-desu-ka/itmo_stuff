#pragma once

#include "../../managers/ManagerIncluder.hpp"

class Manager { //синглтон, задача которого более удобный доступ к менеджерам данных (задач, работников, отчетов и логов)
protected:
    Manager() {} //нужно, чтобы сделать синглтоном
    static Manager *manager; //нужно, чтобы сделать синглтоном
public:
    Manager(Manager &other) = delete; //нужно, чтобы сделать синглтоном
    void operator=(const Manager&) = delete; //нужно, чтобы сделать синглтоном
    static Manager *get() { //нужно, чтобы сделать синглтоном
        if(manager == nullptr){
            manager = new Manager();
        }
        return manager;
    }
    TaskManager taskManager = TaskManager();
    HRManager hrManager = HRManager();
    LogManager logManager = LogManager();
};