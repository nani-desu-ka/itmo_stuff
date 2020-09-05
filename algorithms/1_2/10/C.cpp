#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector <tuple <int, int, int>> heh;
int *parent;

void make_set (int v) {
	parent[v] = v;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b)
		parent[b] = a;
}

int main() {
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    parent = new int [n + 1];
    for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
    for (int i = 0; i < m; i++) {
        int temp_1, temp_2, temp_3;
        cin >> temp_1 >> temp_2 >> temp_3;
        heh.push_back(make_tuple(temp_3, temp_1 - 1, temp_2 - 1));
    }
    sort(heh.begin(), heh.end());
    long long total_weight = 0;
    for (tuple <int, int, int> i : heh) {
        if (find_set(get<1>(i)) != find_set(get<2>(i))) {
            union_sets(get<1>(i), get<2>(i));
            total_weight += get<0>(i);
        }
    }
    cout << total_weight;
    return 0;
}
