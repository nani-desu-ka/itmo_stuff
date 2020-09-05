#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int mem[101][101];
    bool kek = true;
    int n = 0, m = 0;
    int node_1 = 0, node_2 = 0;
    in >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mem[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        in >> node_1 >> node_2;
        if (node_1 > node_2) {
            swap(node_1, node_2);
        }
        if (mem[node_1][node_2] == 1) {
            kek = false;
            break;
        } else {
            mem[node_1][node_2] = 1;
        }
    }
    if (kek) {
        out << "NO";
    } else {
        out << "YES";
    }
    return 0;
}
