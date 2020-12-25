#pragma once

#include "Employer.hpp"

class Rabotyaga : public Employer {
public:
    Rabotyaga(std::string, Employer *);
    void writeReport() override;
};