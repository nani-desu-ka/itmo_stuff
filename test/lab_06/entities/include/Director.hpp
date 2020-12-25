#pragma once

#include "Employer.hpp"

class Director : public Employer {
public:
    Director();
    void writeReport() override;
};