#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Finds the outermost flipped cow by area. Returns (-1, -1) if all zero.
// This is the WRONG strategy.
pair<int, int> find_outermost_tile(vector<vector<int>>& grid) {
  int n = grid.size();

  for (int layer = n - 1; layer >= 0; --layer) {
    if (grid[layer][layer] == 1) {
      return {layer, layer};
    }

    for (int i = layer - 1; i >= 0; --i) {
      if (grid[layer][i] == 1) return {layer, i};
      if (grid[i][layer] == 1) return {i, layer};
    }

  }

  return {-1, -1};
}


void flip(vector<vector<int>>& grid, pair<int, int>& bottom_right) {
  for (int i = 0; i <= bottom_right.first; ++i) {
    for (int j = 0; j <= bottom_right.second; ++j) {
      if (grid[i][j] == 0) {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 0;
      }
    }
  }
}

int main() {
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);

  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    string line;
    cin >> line;
    for (int j = 0; j < n; ++j) {
      grid[i][j] = line[j] - '0'; // Convert char '0' or '1' to int 0 or 1
    }
  }

  pair<int, int> neg = {-1, -1};
  pair<int, int> outermost = find_outermost_tile(grid);

  int result = 0;
  while (outermost != neg) {
    flip(grid, outermost); 
    outermost = find_outermost_tile(grid);
    ++result;
  }

  cout << result << endl;
  return 0;
}

