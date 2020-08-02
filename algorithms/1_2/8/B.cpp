#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int mem[101][101];
    int n = 0;
    int temp_1 = 0;
    bool kek = true;
    in >> n;
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            in >> temp_1;
            mem[i][y] = temp_1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int y = 0; y < n; y++) {
            if (mem[i][y] != mem[y][i]) {
                kek = false;
                break;
            }
            if (i == y && mem[i][y] != 0) {
                kek = false;
                break;
            }
        }
    }
    if (kek) {
        out << "YES";
    } else {
        out << "NO";
    }
    return 0;
}
