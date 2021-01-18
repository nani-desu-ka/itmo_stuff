cmake_minimum_required(VERSION 3.15)
project(lab_06)

set(CMAKE_CXX_STANDARD 14)


add_executable(lab_06 main.cpp entities/include/Employer.hpp entities/include/Task.hpp entities/include/Report.hpp
        managers/include/HRManager.hpp managers/include/TaskManager.hpp
        entities/include/Manager.hpp
        managers/include/LogManager.hpp managers/ManagerIncluder.hpp entities/src/Employer.cpp
        managers/src/HRManager.cpp utils/Enums.hpp UserInterface.hpp UserInterface.cpp utils/CustomExceptions.hpp
        entities/src/Task.cpp managers/src/TaskManager.cpp managers/src/LogManager.cpp
        utils/TimeChecker.hpp
        entities/src/Manager.cpp entities/src/Report.cpp entities/include/TotalDayReport.hpp entities/include/TotalSprintReport.hpp)