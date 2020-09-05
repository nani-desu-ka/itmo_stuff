#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

string pattern;
string search_area;
queue<int> position;
vector<int> prefix;

void prefix_search (string s) {
    prefix.push_back(0);
    for (int i = 1; i < s.size(); i++) {
        int temp = prefix[i - 1];
        while (temp > 0 && s[i] != s[temp]) {
            temp = prefix[temp - 1];
        }
        if (s[temp] == s[i])
            prefix.push_back(++temp);
        else
            prefix.push_back(temp);
    }
}

int pattern_search (int i) {
    if (prefix[pattern.size() + i + 1] != pattern.size()) return 0;
    position.push(i - pattern.size() + 2);
    return 1;
}

int main () {
    ifstream in("search2.in");
    ofstream out("search2.out");
    in >> pattern;
    in >> search_area;
    int amount = 0;
    prefix_search(pattern + '#' + search_area);
    for (int i = 0; i < search_area.size(); i++) {
        amount += pattern_search(i);
    }
    out << amount << '\n';
    while (!position.empty()) {
        out << position.front() << ' ';
        position.pop();
    }
    return 0;
}