#include <iostream>

// тута разные исключения

class SelectorException: public std::exception {
    std::string _error;
public:
    SelectorException(std::string);
    const char * what() const noexcept override;
};

class EmployerException: public std::exception {
    std::string _error;
public:
    EmployerException(std::string);
    const char * what() const noexcept override;
};

class TaskException: public std::exception {
    std::string _error;
public:
    TaskException(std::string);
    const char * what() const noexcept override;
};

class LogException: public std::exception {
    std::string _error;
public:
    LogException(std::string);
    const char * what() const noexcept override;
};