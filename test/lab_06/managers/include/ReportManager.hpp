#pragma once

#include "../../entities/include/Report.hpp"
#include <iostream>

class ReportManager {
public:
    std::vector<Report> total_sprint_reports; // хранлище отчетов за спринт
};