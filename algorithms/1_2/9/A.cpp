#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
  
std::vector <std::vector<int>> array(100001);
int *color;
std::stack <int> final;
bool global = false;
 
void dfs (int node) {
	if (global) return;
    color[node] = 1;
    for (int i = 0; i < array[node].size(); i++) {
        if (color[array[node][i]] == 0) {
            dfs(array[node][i]);
        } else if (color[array[node][i]] == 1) {
        	global = true;
        	return;
		}
    }
    color[node] = 2;
    final.push(node);
}
  
int main() {
    std::ofstream out;
    out.open("topsort.out");
    std::ifstream in;
    in.open("topsort.in");
    int n, m;
    in >> n >> m;
    color = new int [n + 1];
    for (int i = 0; i <= n; i++) {
        color[i] = 0;
    }
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        in >> temp_1 >> temp_2;
        array[temp_1].push_back(temp_2);
    }
    for (int i = 1; i < n + 1; i++) {
        if (color[i] == 0 && !global) {
            dfs(i);
        }
    }
    while (!final.empty() && !global) {
        out << final.top() << ' ';
        final.pop();
    }
    if (global) {
    	out << "-1";
	}
    return 0;
}
