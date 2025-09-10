#include<bits/stdc++.h>

using namespace std;

void trace_path(vector<vector<char>> grid, set<pair<int, int>> edges, pair<int, int> current) {
	if (edges.count(current) != 0) {
		return;
	}
	edges.insert(current);
	// Get all the neighbors
	int i = current.first;
	int j = current.second;
	vector<pair<int, int>> pairs = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}, {i+1,j+1}, {i-1, j-1}, {i+1, j-1}, {i-1, j+1}};
	for (auto p : pairs) {
		if (0 <= p.first && p.first < grid.size() && 0 <= p.second && p.second < grid[0].size()) {
			if (grid[p.first][p.second] == '#') {
				trace_path(grid, edges, p);
			}
		}
	}
}

int main() {
	freopen("inputt", "r", stdin);
	int m; int n;
	cin >> m; cin >> n;
	vector<vector<char>> grid;

	set<set<pair<int, int>>> all_fills = {};

	for (int i = 1; i <= m; ++i) {
		vector<char> row;
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			row.push_back(c);	
		}
		grid.push_back(row);
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			set<pair<int, int>> new_fill;
			new_fill.insert({i, j});
			if (grid[i][j] == '#') {
				trace_path(grid, new_fill, {i, j});
				all_fills.insert(new_fill);
			}
		}
	}

	cout << all_fills.size() << endl;
	
	return 0;
}
