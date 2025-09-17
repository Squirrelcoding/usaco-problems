#include<bits/stdc++.h>

using namespace std;

void flood_fill(vector<vector<char>>& grid, set<pair<int, int>>& fill, pair<int, int> current, set<pair<int, int>>& visited_cells) {
	// If the current cell is in the fill, return
	if (visited_cells.count(current) > 0) {
		return;
	}

	// Insert the cell
	fill.insert(current);
	visited_cells.insert(current);

	// Get all the neighbors
	int i = current.first;
	int j = current.second;

	// All of the neighbor candidates
	vector<pair<int, int>> pairs = {
		{i+1, j}, 
		{i+1,j+1}, 
		{i+1, j-1}, 
		{i-1, j}, 
		{i-1, j+1},
		{i-1, j-1}, 
		{i, j+1}, 
		{i, j-1}, 
	};

	for (auto p : pairs) {

		// If the neighbor is in the grid, check it. 
		if (0 <= p.first && p.first < grid.size() && 0 <= p.second && p.second < grid[0].size()) {
			if (grid[p.first][p.second] == '#') {
				flood_fill(grid, fill, p, visited_cells);
			}
		}
	}
}

int main() {
	freopen("inputt", "r", stdin);
	int m; int n;
	cin >> m; cin >> n;
	vector<vector<char>> grid;

	set<pair<int, int>> visited_cells = {};

	for (int i = 1; i <= m; ++i) {
		vector<char> row;
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			row.push_back(c);	
		}
		grid.push_back(row);
	}

	int c = 0;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] != '#') continue;
			if (visited_cells.count({i, j}) > 0) continue;

			// Start a new fill
			set<pair<int, int>> new_fill;

			// Fill the fill
			flood_fill(grid, new_fill, {i, j}, visited_cells);

			visited_cells.insert({i, j});

			c++;
		}
	}

	cout << c << endl;
	
	return 0;
}
