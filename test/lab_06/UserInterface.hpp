#pragma once

#include "iostream"
#include "entities/include/Employer.hpp"
#include "utils/Enums.hpp"
#include "entities/include/Manager.hpp"
#include "entities/include/Task.hpp"

class UserInterface { // ���孨� �஢���, ��� ���짮��⥫� ������������� � �ணࠬ���
public:
//    UserInterface() = default;
    void hire_new_employer(std::string, Employer * = nullptr); //������ ࠡ�⭨��
    void new_teamlead(Employer *); //ᤥ���� ���㤭��� ⨬�����
    void set_new_head(Employer *, Employer *); //ᤥ���� ���㤭��� ��砫쭨��� ��㣮�� ���㤭���
    void fire_employer(Employer *); //㢮�쭥���
    Employer *find_employer(std::string); //���� ࠡ�⭨�� �� ��� �����
    std::vector<Task> find_tasks(std::string, Selector); //���� ����� �� �६���
    Task &find_task(int); //���� ����� �� ID
    std::vector<Task> find_tasks(Employer *, Selector); //���� ����� �� ࠡ�⭨��
    void end_day(); //�����稢��� ���� � ���⠢��� ��� ࠡ�⭨��� ����� ��������� ९���
    void start_sprint(); //��稭��� �ਭ�
    std::vector<TotalSprintReport> end_sprint(); //�����稢��� �ਭ�
    void print_ierarchy(); //���⠥� ������ (����ᨬ���� ����⭠ �� ����㯠�)
private:
    bool sprint_active = false;
};