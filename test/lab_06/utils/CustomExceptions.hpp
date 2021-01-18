#include <iostream>

//тута разные исключения

class SelectorException: public std::exception {
    std::string _error;
public:
    SelectorException(std::string error) : _error(error){}
    const char * what() const noexcept {
        return _error.c_str();
    }
};

class EmployerException: public std::exception {
    std::string _error;
public:
    EmployerException(std::string error) : _error(error){}
    const char * what() const noexcept {
        return _error.c_str();
    }
};

class TaskException: public std::exception {
    std::string _error;
public:
    TaskException(std::string error) : _error(error){}
    const char * what() const noexcept {
        return _error.c_str();
    }
};

class LogException: public std::exception {
    std::string _error;
public:
    LogException(std::string error) : _error(error){}
    const char * what() const noexcept {
        return _error.c_str();
    }
};