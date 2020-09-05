#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
vector <vector <int>> mem(100001);
vector <int> mem_2(100001);
int *was;
bool cycle = false;
stack <int> first;
int end_point;
int start_point;

void dfs (int node) {
	was[node] = 1;
    for (int i = 0; i < mem[node].size(); i++) {
        int new_node = mem[node][i];
        if (was[new_node] == 1) {
        	end_point = new_node;
        	cycle = true;
        	start_point = node;
        } else if (was[new_node] == 0) {
        	mem_2[new_node] = node;
        	dfs(new_node);
		}
    }
    was[node] = 2;
}
 
int main () {
    int n, m;
    stack <int> second;
    cin >> n >> m;
    was = new int [n+1];
    for (int i = 0; i <= n; i++) {
        was[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        mem[temp_1].push_back(temp_2);
    }
    for (int i = 1; i <=n; i++) {
        if (was[i] == 0) {
            dfs(i);
        }   
    }
    if (!cycle) {
        cout << "NO";
    } else {
    	first.push(end_point);
    	int temp_point = start_point;
    	while (temp_point != end_point) {
    		first.push(temp_point);
    		temp_point = mem_2[temp_point];
		}
        cout << "YES" << '\n';
        while (!first.empty()) {
        	cout << first.top() << ' ';
        	first.pop();
		}
    }
    return 0;
}
