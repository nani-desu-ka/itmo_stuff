#pragma once
#include <iostream>

class Exception: public std::exception {
    std::string _error;

public:
    Exception(std::string);

    const char * what() const noexcept override;
};