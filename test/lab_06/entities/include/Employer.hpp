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
    int create_task(std::string, std::string = ""); //ᮧ���� ��� (�����頥� id �᪨ ��� ����� 㤮���� ࠡ���)
    void activate_task(int); //��⨢�஢��� ���
    void resolve_task(int); //������� ���
    void modify_task(int, std::string); //�������� ���ᠭ��
    std::vector<int> check_resolved_tasks();
    void write_report();
    void clean_reports();
    std::vector<TotalSprintReport> write_sprint(); //ࠡ�稥 ������� ����� �� ᢮�� ���稭����� (��⮤ �ᯮ���� ⮫쪮 ࠡ�� ��砫쭨�)
    TotalSprintReport compile_sprint(); //⨬���� ᮡ���� �� ९���� � ���� (��⮤ �ᯮ���� ⮫쪮 ⨬���)
    std::vector<TotalSprintReport> get_sprint(); //��४�� ����砥� �ਭ� ९���� �� ��� ⨬����� (��⮤ �ᯮ���� ⮫쪮 ��४��)

    const std::string name;
    Employer *head;
protected:
    std::list<Employer *> vassals;
    std::vector<int> accessible_tasks;
    TotalDayReport day_reports;
    TotalSprintReport sprint_reports;
};
