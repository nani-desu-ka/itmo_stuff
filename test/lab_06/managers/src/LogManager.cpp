#include "../include/LogManager.hpp"
#include "../../utils/CustomExceptions.hpp"

void LogManager::add_log_note(std::string time, std::string log_note) {
    _log[time].push_back(log_note);
}
std::vector<std::string> LogManager::find_log_notes_by_time(std::string time) {
    if (_log.find(time) == _log.end()) throw LogException("log_file_not_found");
    return _log[time];
}
std::unordered_map<std::string, std::vector<std::string>> LogManager::get_all_notes() {
    return _log;
}