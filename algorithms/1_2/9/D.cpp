#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector <int>> mem_1(200001);
vector <vector <int>> mem_2(200001);
bool *was;
int *component_number;
int component_number_ = 1;
bool cycle = false;
stack <int> first;

void dfs_1 (int node) {
	was[node] = true;
	for (int i = 0; i < mem_1[node].size(); i++) {
		int new_node = mem_1[node][i];
		if (!was[new_node]) {
			dfs_1(new_node);
		} 
	}
	first.push(node);
}

void dfs_2 (int node) {
	was[node] = true;
	component_number[node] = component_number_;
	for (int i = 0; i < mem_2[node].size(); i++) {
		int new_node = mem_2[node][i];
		if (!was[new_node]) {
			dfs_2(new_node);
		} 
	}
}

int main () {
	int n, m;
	stack <int> second;
	cin >> n >> m;
	was = new bool [n+1];
	for (int i = 0; i <= n; i++) {
		was[i] = false;
	}
	component_number = new int [n+1];
	for (int i = 0; i <= n; i++) {
		component_number[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int temp_1, temp_2;
		cin >> temp_1 >> temp_2;
		mem_1[temp_1].push_back(temp_2);
		mem_2[temp_2].push_back(temp_1);
	}
	for (int i = 1; i <= n; i++) {
		if (!was[i]) {
			dfs_1(i);
		}	
	}
	for (int i = 1; i <= n; i++) {
		was[i] = false;
	}
	while (!first.empty()) {
//		cout << first.top();
		if (!was[first.top()]) {
//			cout << "here" << '\n';
			dfs_2(first.top());
			component_number_++;
		}	
		first.pop();
	}
	cout << --component_number_ << '\n';
	for (int i = 1; i <= n; i++) {
		cout << component_number[i] << ' ';
	}
	return 0;
}
