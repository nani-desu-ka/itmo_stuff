#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
vector <vector <int>> mem(200001);
stack <int> kek;
bool *was;

void dfs (int node) {
	was[node] = true;
    for (int i = 0; i < mem[node].size(); i++) {
        int new_node = mem[node][i];
        if (!was[new_node]) {
        	dfs(new_node);
    	}
	}
    kek.push(node);
}
 
int main () {
	freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    int n, m;
    bool check = false;
    cin >> n >> m;
    was = new bool [n + 1];
    for (int i = 0; i < n + 1; i++) {
    	was[i] = false;
	}
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        mem[temp_1].push_back(temp_2);
    }
    for (int i = 1; i < n + 1; i++) {
    	if (!was[i]) {
    		dfs(i);
		}
	}
//	while (!kek.empty()) {
//		cout << kek.top();
//		kek.pop();
//	}
	bool temp_bool = false;
	int temp_1 = kek.top();
	int temp_2;
	kek.pop();
	while (!kek.empty()) {
		temp_2 = kek.top();
		for (int i = 0; i < mem[temp_1].size(); i++) {
			if (mem[temp_1][i] == temp_2) {
				temp_bool = true;
			}
		}
		if (!temp_bool) {
			check = true;
			break;
		}
		temp_1 = temp_2;
		kek.pop();
		temp_bool = false;
	}
	if (check) {
		cout << "NO";
	} else {
		cout << "YES";
	}
    return 0;
}
