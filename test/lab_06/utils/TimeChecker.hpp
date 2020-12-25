#pragma once

#include <iostream>
#include <ctime>

class TimeChecker {
public:
    static std::string get_time() {
        char buffer[80];
        time_t seconds = time(NULL);
        tm* timeinfo = localtime(&seconds);
        char* format = "%d-%B-%Y %H:%M";
        strftime(buffer, 80, format, timeinfo);
        return buffer;
    }
};