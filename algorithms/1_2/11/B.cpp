#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int **matrix;

int main() {
    ifstream in("pathsg.in");
    ofstream out("pathsg.out");
    int inf = INT_MAX;
    int n, m;
    in >> n >> m;
    matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
    	matrix[i] = new int [n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) matrix[i][j] = 0;
			else matrix[i][j] = inf;
		}
	} 
    for (int i = 0; i < m; ++i) {
    	int temp_1, temp_2, temp_3;
    	in >> temp_1 >> temp_2 >> temp_3;
    	matrix[temp_1 - 1][temp_2 - 1] = temp_3;
    }    
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (matrix[i][k] < inf && matrix[k][j] < inf)
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		out << matrix[i][j] << ' ';
		}
		out << '\n';
    }    
    return 0;
}
