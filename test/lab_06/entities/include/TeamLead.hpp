#pragma once

#include "Employer.hpp"

class TeamLead : public Employer {
public:
    TeamLead(std::string);
    void writeReport() override;
};