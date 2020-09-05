#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector <vector<int>> mem(100001);
int counter[100001] = {0};
int component_number = 1;
bool was = false;
void dfs (int index) {
    if (counter[index] != 0) {
        return;
    } else {
        counter[index] = component_number;
        was = true;
    }
    for (int i = 0; i < mem[index].size(); i++) {
        dfs(mem[index][i]);
    }
}

int main() {
    ifstream in("components.in");
    ofstream out("components.out");
    int n = 0, m = 0;
    int first = 0, second = 0;
    in >> n >> m;
    for (int i = 0; i < m; i++) {
        in >> first >> second;
        mem[first].push_back(second);
        mem[second].push_back(first);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
        if (was) {
            component_number++;
            was = false;
        }
    }
    if (component_number > 0) component_number--;
    out << component_number << '\n';
    for (int i = 1; i <= n; i++) {
        out << counter[i] << ' ';
    }
    return 0;
}
