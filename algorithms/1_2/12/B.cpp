#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool used[501];
vector<vector<tuple<int, int>>> vertex(501);
int end_v = 0;
int end_v_sat = 0;

class edge {
public:
    edge (int from, int to, int capacity) : from(from), to(to), capacity(capacity), saturation(0) {};
    int from;
    int to;
    int capacity;
    int saturation;
};

vector<edge> edges;

int dfs_1(int from, int temp_min) {
    if (from == end_v || temp_min == 0) return temp_min;
    used[from] = true;
    for (auto v : vertex[from]) {
        if (used[get<0>(v)]) continue;
        if (edges[get<1>(v)].capacity > edges[get<1>(v)].saturation) {
            int new_sat = dfs_1(get<0>(v), min(temp_min, edges[get<1>(v)].capacity - edges[get<1>(v)].saturation));
            if (new_sat > 0) {
                edges[get<1>(v)].saturation += new_sat;
                edges[get<1>(v) ^ 1].saturation -= new_sat;
                return new_sat;
            }
        }
    }
    return 0;
}

void t_income() {
    while (true) {
        for (int i = 0; i < 501; i++) used[i] = false;
        int new_path_sat = dfs_1(0,  1000000);
        if (new_path_sat == 0) return;
        else end_v_sat += new_path_sat;
    }
}

int main () {
    ifstream in("matching.in");
    ofstream out("matching.out");
    for (int i = 0; i < 501; i++) {
      used[i] = false;
    }
    int m;
    int first_half;
    int second_half;
    in >> first_half >> second_half >> m;
    end_v = first_half + second_half + 1;
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2;
        in >> temp_1 >> temp_2;
        vertex[temp_1].push_back(make_tuple(temp_2 + first_half, edges.size()));
        edge new_one(temp_1, temp_2 + first_half, 1);
        edges.push_back(new_one);
        vertex[temp_2 + first_half].push_back(make_tuple(temp_1, edges.size()));
        edge new_one_2(temp_2 + first_half, temp_1, 0);
        edges.push_back(new_one_2);
    }
    for (int temp_2 = 1; temp_2 <= first_half; temp_2++) {
        int temp_1 = 0;
        vertex[temp_1].push_back(make_tuple(temp_2, edges.size()));
        edge new_one(temp_1, temp_2, 1);
        edges.push_back(new_one);
        vertex[temp_2].push_back(make_tuple(temp_1, edges.size()));
        edge new_one_2(temp_2, temp_1, 0);
        edges.push_back(new_one_2);
    }
    for (int temp_1 = first_half + 1; temp_1 <= first_half + second_half; temp_1++) {
        int temp_2 = first_half + second_half + 1;
        vertex[temp_1].push_back(make_tuple(temp_2, edges.size()));
        edge new_one(temp_1, temp_2, 1);
        edges.push_back(new_one);
        vertex[temp_2].push_back(make_tuple(temp_1, edges.size()));
        edge new_one_2(temp_2, temp_1, 0);
        edges.push_back(new_one_2);
    }
    t_income();
    out << end_v_sat;
    return 0;
}                                          