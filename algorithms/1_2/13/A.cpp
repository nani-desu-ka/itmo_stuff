#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

string pattern;
string search_area;
queue<int> position;

int needle_search (int number) {
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] != search_area[i + number]) return 0;
    }
    position.push(number + 1);
    return 1;
}

int main () {
    ifstream in("search1.in");
    ofstream out("search1.out");
    in >> pattern;
    in >> search_area;
    int amount = 0;
    if (!search_area.empty() && search_area.size() >= pattern.size())
        for (int i = 0; i <= search_area.size() - pattern.size(); i++) {
            amount += needle_search(i);
        }
    out << amount << '\n';
    while (!position.empty()) {
        out << position.front() << ' ';
        position.pop();
    }
    return 0;
}