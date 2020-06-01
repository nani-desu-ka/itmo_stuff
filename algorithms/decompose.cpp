#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool used[501];
vector<vector<pair<int, int>>> vertex(501);
int end_v = 0;
int end_v_sat = 0;

class edge {
public:
    edge (int from, int to, int capacity, int index) : from(from), to(to), capacity(capacity), saturation(0), index(index) {};
    int from;
    int to;
    int capacity;
    int saturation;
    int index;
};

vector<edge> edges;
vector<edge> temp_edges;

class path {
public:
    path(vector<edge> temp, int saturation) : one_by_one(temp), saturation(saturation){}
    vector<edge> one_by_one;
    int saturation;
};

vector <path> path_info;

int dfs_1(int from, int temp_min) {
    if (from == end_v || temp_min == 0) return temp_min;
    used[from] = true;
    for (auto v : vertex[from]) {
        if (used[v.first]) continue;
        if (edges[v.second].capacity > edges[v.second].saturation) {
            int new_sat = dfs_1(v.first, min(temp_min, edges[v.second].capacity - edges[v.second].saturation));
            if (new_sat > 0) {
                edges[v.second].saturation += new_sat;
                edges[v.second ^ 1].saturation -= new_sat;
                temp_edges.push_back(edges[v.second]);
                return new_sat;
            }
        }
    }
    return 0;
}

void t_income() {
    while (true) {
        for (int i = 0; i < 501; i++) used[i] = false;
        int new_path_sat = dfs_1(0,  1000000000);
        if (new_path_sat == 0) return;
        path temp_path(temp_edges, new_path_sat);
        temp_edges.clear();
        path_info.push_back(temp_path);
        end_v_sat += new_path_sat;
    }
}

int main () {
    for (int i = 0; i < 501; i++) {
        used[i] = false;
    }
    int m;
    cin >> end_v >> m;
    end_v--;
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2, temp_3;
        cin >> temp_1 >> temp_2 >> temp_3;
        vertex[temp_1 - 1].push_back(make_pair(temp_2 - 1, edges.size()));
        edge new_one(temp_1 - 1, temp_2 - 1, temp_3, i + 1);
        edges.push_back(new_one);
        vertex[temp_2 - 1].push_back(make_pair(temp_1 - 1, edges.size()));
        edge new_one_2(temp_2 - 1, temp_1 - 1, 0, i + 1);
        edges.push_back(new_one_2);
    }
    t_income();
    cout << path_info.size() << '\n';
    for (auto i : path_info) {
        cout << i.saturation << ' ';
        cout << i.one_by_one.size() << ' ';
        reverse(i.one_by_one.begin(), i.one_by_one.end());
        for(auto j : i.one_by_one) {
            cout << j.index << ' ';
        }
        cout << '\n';
    }
    return 0;
}