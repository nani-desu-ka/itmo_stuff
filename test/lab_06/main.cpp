#include <iostream>
#include "utils/TimeChecker.hpp"
#include "UserInterface.hpp"

int main() {
    UserInterface interface = UserInterface();
    interface.hire_new_employer("Subject");
    interface.hire_new_employer("Subject_2");
    interface.hire_new_employer("Subject_3");
    interface.new_teamlead(interface.find_employer("Subject"));
    interface.new_teamlead(interface.find_employer("Subject_2"));
    interface.set_new_head(interface.find_employer("Subject_3"), interface.find_employer("Subject"));

    interface.start_sprint(); //��砫� �ਭ�

    int task_id = interface.find_employer("Subject_3")->create_task("Some task", "Some description");
    interface.find_employer("Subject_3")->activate_task(task_id);

    interface.end_day(); //����ᠫ� ९��� �� ����

    int task_id_2 = interface.find_employer("Subject_2")->create_task("Another task", "Another description");
    interface.find_employer("Subject_2")->activate_task(task_id_2);
    interface.find_employer("Subject_2")->resolve_task(task_id_2);
    interface.find_employer("Subject_3")->resolve_task(task_id);

    interface.end_day(); //����ᠫ� ९��� �� ����
    interface.end_day(); //����ᠫ� ९��� �� ����

    interface.print_ierarchy();

    std::cout << '\n';

    std::vector<TotalSprintReport> teamlead_reports = interface.end_sprint(); //�����稫� �ਭ� � ����稫� ९���� ⨬�����
    for (auto sprint_report : teamlead_reports) {
        for (auto report : sprint_report.sprint_reports) {
            for (auto message : report.reports_during_day) {
                std::cout << message.get_task_id() << ' ' << message.get_time() << ' ' << message.get_change_type() << '\n';
            }
        }
        std::cout << '\n';
    }
    return 0;
}
