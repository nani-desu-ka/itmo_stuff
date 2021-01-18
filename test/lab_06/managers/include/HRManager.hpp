#pragma once

#include "../../entities/include/Director.hpp"
#include <list>

class HRManager { // �������� ࠡ�⭨���
public:
    Employer *director = new Director(); // ᠬ� ������ �� �।���⨨, � ���� � ���稭���� �� ⨬����
    void add_employer(Employer *);
    void remove_employer(Employer *);
    Employer *get_employer_by_name(std::string);
private:
    std::vector<Employer *> employers; // �࠭���� ���㤭����
};