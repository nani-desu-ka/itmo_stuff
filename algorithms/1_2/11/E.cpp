#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 100000;

int main()
{
    ifstream in("negcycle.in");
    ofstream out("negcycle.out");
    int n;
    in >> n;
    vector<vector<int>> matrix(n);
    vector <long long> path(n, 0);
    vector <int> prev(n, -1);
    vector<int> way;
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		in >> matrix[i][j];
		}
	}
    for (int i = 0; i < n; ++i)
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                if (matrix[u][v] != inf && path[v] > path[u] + matrix[u][v]) {
                    path[v] = path[u] + matrix[u][v];
                    prev[v] = u;
                }
    bool was = false;
    for (int u = 0; u < n; ++u) {
        if (was)
            break;
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] != inf && path[v] > path[u] + matrix[u][v]) {
                for (int i = 0; i < n; ++i)
                    v = prev[v];
                way.push_back(v);
				u = v;
                while (u != prev[v]) {
                    v = prev[v];
                    way.push_back(v);
                }
                was = true;
                reverse(way.begin(), way.end());
                break;
            }
        }
    }

    if (way.empty()) {
        out << "NO";
    } else {
        out << "YES" << '\n';
		out << way.size() + 1 << '\n';
        for (int v : way) {
            out << v + 1 << " ";
        }
        out << way[0] + 1;
    }
    return 0;
}
