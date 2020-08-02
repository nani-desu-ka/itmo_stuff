#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
  
int main() {
//    ifstream in("pathbgep.in");
//    ofstream out("pathbgep.out");
    int inf = INT_MAX;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> list(n + 1);
    vector<int> vertices(n + 1, inf);
    set<pair<int, int>> vert;
    for (int i = 1; i <= m; ++i) {
        int temp_1, temp_2, temp_3;
        cin >> temp_1 >> temp_2 >> temp_3;
        list[temp_1].push_back(make_pair(temp_2, temp_3));
        list[temp_2].push_back(make_pair(temp_1, temp_3));
    }    
    vertices[1] = 0;
    vert.insert(make_pair(vertices[1], 1));
	while (!vert.empty()) {
		int v = vert.begin()->second;
		vert.erase(vert.begin());
		for (size_t j = 0; j < list[v].size(); ++j) {
			int to = list[v][j].first;
			int len = list[v][j].second;
			if (vertices[v] + len < vertices[to]) {
				vert.erase (make_pair(vertices[to], to));
				vertices[to] = vertices[v] + len;
				vert.insert(make_pair(vertices[to], to));
			}
		}
	}
    for (int i = 1; i <= n; ++i) {
    	cout << vertices[i] << ' ';
  	}
    return 0;
}
