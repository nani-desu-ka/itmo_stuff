#include <iostream>
//#include <queue>
#include <vector>
#include <fstream>

using namespace std;

//string pattern;
string search_area;
//queue<int> position;
vector<int> prefix;

void prefix_search (string s) {
    prefix.push_back(0);
    for (int i = 1; i < s.size(); i++) {
        int temp = prefix[i - 1];
        while (temp > 0 && s[i] != s[temp]) {
            temp = prefix[temp - 1];
        }
        if (s[temp] == s[i])
            prefix.push_back(temp + 1);
        else
            prefix.push_back(temp);
    }
}

//int pattern_search (int i) {
//    if (prefix[pattern.size() + i] != pattern.size()) return 0;
//    position.push(i);
//    return 1;
//}

int main () {
    ifstream in("prefix.in");
    ofstream out("prefix.out");
    in >> search_area;
//    int amount = 0;
    prefix_search(search_area);
//    for (int i = 0; i < search_area.size() - 1; i++)
//        amount += pattern_search(i + 1);
    for (auto i : prefix) {
        out << i << ' ';
    }
    return 0;
}