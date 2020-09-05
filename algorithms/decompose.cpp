#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, capacity, saturation, index;
};

vector<int> temp_edges;

class path {
public:
    path(vector<int> temp, long long saturation) : one_by_one(std::move(temp)), saturation(saturation){}
    vector<int> one_by_one;
    long long saturation;
};

vector <path> path_info;

vector<vector<int>> vertex;
vector<int> ptr;
vector<Edge> edges;
vector<int> level;

int n = 0, m = 0, sink = 0;

int dfs(int from = 0, int temp_saturation = INT_MAX) {
    if (!temp_saturation)
        return 0;
    if (from == sink)
        return temp_saturation;
    while (ptr[from] < vertex[from].size()) {
        int edge = vertex[from][ptr[from]];
        if (level[from] + 1 == level[edges[edge].to]){
            int new_sat = dfs(edges[edge].to, min(temp_saturation, edges[edge].capacity - edges[edge].saturation));
            if (new_sat) {
                edges[edge].saturation += new_sat;
                edges[edge ^ 1].saturation -= new_sat;
                temp_edges.push_back(edges[edge].index);
                return new_sat;
            }
        }
        ptr[from]++;
    }
    return 0;
}

bool bfs() {
    level.assign(n, 0);
    queue<int> q;
    q.push(0);
    level[0] = 1;
    while (!q.empty() && !level[sink]) {
        int from = q.front();
        q.pop();
        for (auto &edge : vertex[from]) {
            if (!level[edges[edge].to] && edges[edge].capacity > edges[edge].saturation) {
                q.push(edges[edge].to);
                level[edges[edge].to] = level[from] + 1;
            }
        }
    }
    return level[sink];
}

int main() {
    cin >> n >> m;
    vertex.resize(n);
    ptr.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        vertex[from - 1].push_back(edges.size());
        edges.push_back(Edge{to - 1, capacity, 0, i + 1});
        vertex[to - 1].push_back(edges.size());
        edges.push_back(Edge{from - 1, 0, 0, i + 1});
    }
    sink = n - 1;
    while (bfs()) {
        while (true) {
            long long new_path_sat = dfs();
            if (new_path_sat <= 0) break;
            path temp_path(temp_edges, new_path_sat);
            temp_edges.clear();
            path_info.push_back(temp_path);
        }
        ptr.assign(n, 0);
    }
    cout << path_info.size() << '\n';
    for (auto i : path_info) {
        cout << i.saturation << ' ';
        cout << i.one_by_one.size() << ' ';
        reverse(i.one_by_one.begin(), i.one_by_one.end());
        for(auto j : i.one_by_one) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}
