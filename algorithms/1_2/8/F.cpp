#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

bool was[101][101];
queue <pair <int, int>> bfs_queue;
int n = 0, m = 0;
char path[101][101];
pair <int, int> start;
pair <int, int> finish = make_pair(-1, -1);
bool check = false;
vector <char> mem;
void bfs (char **field) {
    pair <int, int> temp;
    while (!bfs_queue.empty()) {
        temp = bfs_queue.front();
        bfs_queue.pop();
        if (temp.second + 1 < m && (field[temp.first][temp.second + 1] == '.' || field[temp.first][temp.second + 1] == 'T') && !was[temp.first][temp.second + 1]) {
            was[temp.first][temp.second + 1] = true;
            path[temp.first][temp.second + 1] = 'R';
            bfs_queue.push(make_pair(temp.first, temp.second + 1));
            if (temp.first == finish.first && temp.second + 1 == finish.second) {
                check = true;
                break;
            }
        }
        if (temp.first + 1 < n && (field[temp.first + 1][temp.second] == '.' || field[temp.first + 1][temp.second] == 'T') && !was[temp.first + 1][temp.second]) {
            was[temp.first + 1][temp.second] = true;
            path[temp.first + 1][temp.second] = 'D';
            bfs_queue.push(make_pair(temp.first + 1, temp.second));
            if (temp.first + 1 == finish.first && temp.second == finish.second) {
                check = true;
                break;
            }
        }
        if (temp.second - 1 >= 0 && (field[temp.first][temp.second - 1] == '.' || field[temp.first][temp.second - 1] == 'T') && !was[temp.first][temp.second - 1]) {
            was[temp.first][temp.second - 1] = true;
            path[temp.first][temp.second - 1] = 'L';
            bfs_queue.push(make_pair(temp.first, temp.second - 1));
            if (temp.first == finish.first && temp.second - 1 == finish.second) {
                check = true;
                break;
            }
        }
        if (temp.first - 1 >= 0 && (field[temp.first - 1][temp.second] == '.' || field[temp.first - 1][temp.second] == 'T') && !was[temp.first - 1][temp.second]) {
            path[temp.first - 1][temp.second] = 'U';
            was[temp.first - 1][temp.second] = true;
            bfs_queue.push(make_pair(temp.first - 1, temp.second));
            if (temp.first - 1 == finish.first && temp.second == finish.second) {
                check = true;
                break;
            }
        }
    }
}

void relax() {
    int i = finish.first;
    int j = finish.second;
    pair <int, int> prev;
    while (make_pair(i, j) != start) {
        mem.push_back(path[i][j]);
        prev = make_pair(i, j);
        if (path[i][j] == 'U') {
            i++;
        } else if (path[i][j] == 'D') {
            i--;
        } else if (path[i][j] == 'R') {
            j--;
        } else if (path[i][j] == 'L') {
            j++;
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    char temp;
    in >> n >> m;
    char **field = new char *[n];
    for (int i = 0; i < n; i++) {
        field[i] = new char [m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> temp;
            field[i][j] = temp;
            was[i][j] = false;
            path[i][j] = 'H';
            if (temp == 'S') {
                start = make_pair(i, j);
            }
            if (temp == 'T') {
                finish = make_pair(i, j);
            }
        }
    }
    bfs_queue.push(start);
    bfs(field);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            out << path[i][j];
//        }
//        out << '\n';
//    }
    if (check && was[finish.first][finish.second]) {
        relax();
        out << mem.size() << '\n';
        for (int i = mem.size() - 1; i >= 0; i--) {
            out << mem[i];
        }
    } else {
        out << "-1";
    }
    return 0;
}