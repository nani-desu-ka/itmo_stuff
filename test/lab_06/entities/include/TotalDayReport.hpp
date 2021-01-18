#pragma once

#include <vector>
#include "Report.hpp"

class TotalDayReport {
public:
    void add(Report report) {
        reports_during_day.push_back(report);
    }
    std::vector<Report> reports_during_day;
};