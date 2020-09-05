#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
  
int main() {
    ifstream in("pathmgep.in");
    ofstream out("pathmgep.out");
    long long inf = LLONG_MAX;
    int n, s, f;
    in >> n >> s >> f;
    vector<vector<pair<int, long long>>> list(n + 1);
    vector<long long> vertices(n + 1, inf);
    vector<bool> vert(n + 1, false);
    for (long long i = 1; i <= n; ++i) {
        int temp;
        for (long long j = 1; j <= n; ++j) {
            in >> temp;
            if (i != j && temp != -1) {
                list[i].push_back(make_pair(j, temp));
            }
        }
    }    
    vertices[s] = 0;
    for (long long i = 0; i < n; ++i) {
		long long v = -1;
		for (long long j = 1; j <= n; ++j)
			if (!vert[j] && (v == -1 || vertices[j] < vertices[v]))
				v = j;
		if (vertices[v] == inf)
			break;
		vert[v] = true;
 
		for (size_t j = 0; j < list[v].size(); ++j) {
			int to = list[v][j].first;
			long long len = list[v][j].second;
			if (vertices[v] + len < vertices[to]) {
				vertices[to] = vertices[v] + len;
			}
		}
	}
//  for (int i = 1; i <= n; ++i) {
//      out << vertices[i] << ' ';
//  }
//  out << inf;
    if (vertices[f] != inf) { 
    	out << vertices[f];
    } else {
        out << -1;
    }
    return 0;
}
