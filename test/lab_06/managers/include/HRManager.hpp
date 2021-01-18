#pragma once

#include "../../entities/include/Employer.hpp"
#include <list>

class HRManager { // �������� ࠡ�⭨���
public:
    Employer *director = new Employer(); // ᠬ� ������ �� �।���⨨, � ���� � ���稭���� �� ⨬����
    void add_employer(Employer *);
    void remove_employer(Employer *);
    Employer *get_employer_by_name(std::string);
    std::vector<Employer *> employers; // �࠭���� ���㤭����
};