#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector <pair<int, int>> mem;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n = 0, m = 0, temp_1 = 0, temp_2 = 0;
    pair <int, int> temp;
    in >> n >> m;
    int mem_2[110][110];
//    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        in >> temp_1 >> temp_2;
//        cin >> temp_1 >> temp_2;
        temp = make_pair(temp_1, temp_2);
        mem.push_back(temp);
    }
    for (int i = 0; i < n + 1; i++) {
        for (int y = 0; y < n + 1; y++) {
            mem_2[i][y] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
         mem_2[mem[i].first][mem[i].second]++;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int y = 1; y < n + 1; y++) {
            out << mem_2[i][y] << ' ';
//            cout << mem_2[i][y] << ' ';
        }
        out << '\n';
//        cout << '\n';
    }
    return 0;
}
