#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n;
    cin >> m;
    int *mem;
    mem = new int [n + 1];
    for (int i = 0; i <= n; i++) {
    	mem[i] = 0;
	}
	for (int i = 0;i < m; i++) {
    	int temp_1;
		int temp_2;
    	cin >> temp_1 >> temp_2;
    	mem[temp_1]++;
		mem[temp_2]++;
	}
	for (int i = 1; i <= n; i++) {
    	cout << mem[i] << ' ';
	}
	return 0;
}
