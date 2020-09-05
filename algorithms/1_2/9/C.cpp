#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
vector <vector <int>> mem(100001);
int *color;
bool kek = false;

void dfs (int node, int color_) {
	if (kek) return;
	color[node] = color_;
    for (int i = 0; i < mem[node].size(); i++) {
        int new_node = mem[node][i];
        if (color[new_node] == 2) {
        	dfs(new_node, (color_ + 1) % 2);
		} else if (color[new_node] != (color_ + 1) % 2) {
			kek = true;
			return;
		}
    }
}
 
int main () {
	freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    int n, m;
    stack <int> second;
    cin >> n >> m;
    color = new int [n + 1];
    for (int i = 1; i <= n; i++) {
    	color[i] = 2;
	}
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        mem[temp_1].push_back(temp_2);
        mem[temp_2].push_back(temp_1);
    }
    for (int i = 1; i <= n; i++) {
    	if (color[i] == 2) {
    		dfs(i, 1);
		}
		if (kek) break;
	}
    if (!kek) {
        cout << "YES";
    } else {
    	cout << "NO";
	}
    return 0;
}
