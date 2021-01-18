#pragma once

#include "../../managers/ManagerIncluder.hpp"

class Manager { //ᨭ��⮭, ����� ���ண� ����� 㤮��� ����� � �������ࠬ ������ (�����, ࠡ�⭨���, ���⮢ � �����)
protected:
    Manager() {} //�㦭�, �⮡� ᤥ���� ᨭ��⮭��
    static Manager *manager; //�㦭�, �⮡� ᤥ���� ᨭ��⮭��
public:
    Manager(Manager &other) = delete; //�㦭�, �⮡� ᤥ���� ᨭ��⮭��
    void operator=(const Manager&) = delete; //�㦭�, �⮡� ᤥ���� ᨭ��⮭��
    static Manager *get() { //�㦭�, �⮡� ᤥ���� ᨭ��⮭��
        if(manager == nullptr){
            manager = new Manager();
        }
        return manager;
    }
    TaskManager taskManager = TaskManager();
    HRManager hrManager = HRManager();
    LogManager logManager = LogManager();
};