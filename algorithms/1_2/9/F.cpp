#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector <int>> mem_1(200001);
bool *was;
bool *player_cells;
stack <int> first;

void game_simulation (int node) {
	was[node] = true;
	for (int i = 0; i < mem_1[node].size(); i++) {
		int new_node = mem_1[node][i];
		if (!player_cells[new_node]) {
			game_simulation(new_node);
			if (player_cells[node] || !player_cells[new_node])
				player_cells[node] = true;
		} 
	}
}

int main () {
	int n, m, s;
	cin >> n >> m >> s;
	player_cells = new bool [n + 1];
	for (int i = 0; i < n + 1; i++) {
		player_cells[i] = false;
	}
	was = new bool [n + 1];
	for (int i = 0; i < n + 1; i++) {
		was[i] = false;
	}
	for (int i = 0; i < m; i++) {
		int temp_1, temp_2;
		cin >> temp_1 >> temp_2;
		mem_1[temp_1].push_back(temp_2);
	}
	game_simulation(s);
	if (player_cells[s]) {
		cout << "First player wins";
	} else {
		cout << "Second player wins";
	}
	return 0;
}
