#pragma once

#include <vector>
#include "TotalDayReport.hpp"

class TotalSprintReport {
public:
    void add(TotalDayReport report) {
        sprint_reports.push_back(report);
    }
    std::vector<TotalDayReport> sprint_reports;
};