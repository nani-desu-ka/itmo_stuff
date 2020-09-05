#include <iostream>
#include <vector>
#include <cmath>
#include <float.h>

using namespace std;

vector <pair <int, int>> mem;
double *min_value;
bool *was;
int *kek;

int main() {
    freopen("spantree.in", "r" , stdin);
    freopen("spantree.out", "w", stdout);
    int n;
    cin >> n;
    was = new bool [n + 1];
    for (int i = 0; i <= n; i++) {
        was[i] = false;
    }
    kek = new int [n + 1];
    for (int i = 0; i <= n; i++) {
        kek[i] = -1;
    }
    min_value = new double [n + 1];
    for (int i = 0; i <= n; i++) {
        min_value[i] = DBL_MAX;
    }
    for (int i = 0; i < n; i++) {
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        mem.push_back(make_pair(temp_1, temp_2));
    }
    double total_weight = 0;
    for (int i = 0; i < n; i++) {
        int current = -1;
        for (int j = 0; j < n; j++) {
			if (!was[j] && (min_value[j] < min_value[current] || current == -1)) {
				current = j;
			}
		}
        if (kek[current] != -1) {
			total_weight += sqrt((mem[kek[current]].first - mem[current].first) * (mem[kek[current]].first - mem[current].first) + 
			(mem[kek[current]].second - mem[current].second) * (mem[kek[current]].second - mem[current].second));
		}
        for (int j = 0; j < n; j++) {
            double temp_dist = sqrt((mem[j].first - mem[current].first) * (mem[j].first - mem[current].first) +
			(mem[j].second - mem[current].second) * (mem[j].second - mem[current].second));
            if (temp_dist < min_value[j]) {
            	kek[j] = current;
                min_value[j] = temp_dist;
            }
        }
        was[current] = true;
    }
    cout.precision(10);
    cout << total_weight;
    return 0;
}
