#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

vector <vector<int>> children(40000);
bool was[40000] = {false};
queue <int> bfs_queue;
int pos[40000] = {0};
void bfs () {
    int temp;
    while (!bfs_queue.empty()) {
        temp = bfs_queue.front();
        bfs_queue.pop();
        for (int i = 0; i < children[temp].size(); i++) {
            if(!was[children[temp][i]]) {
                bfs_queue.push(children[temp][i]);
                was[children[temp][i]] = true;
                pos[children[temp][i]] = pos[temp] + 1;
            }
        }
    }
}

int main() {
    ifstream in("pathbge1.in");
    ofstream out("pathbge1.out");
    int m = 0;
    int first = 0;
    int second = 0;
    int n = 0;
    in >> n >> m;
    for (int i = 0; i < m; i++) {
        in >> first >> second;
        children[first].push_back(second);
        children[second].push_back(first);
    }
    bfs_queue.push(1);
    was[1] = true;
    bfs();
    for (int i = 1; i <= n; i++) {
        out << pos[i] << ' ';
    }
    return 0;
}