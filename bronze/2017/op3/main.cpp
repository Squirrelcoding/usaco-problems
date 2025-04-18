#include <bits/stdc++.h>
#include <vector>

using namespace std;


#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

pair<int, int> get_corner1(vector<vector<int>> &grid, int target) {
  for (int i = 0; i < grid[0].size(); ++i) {
    for (int j = 0; j < grid[0].size() ;++j) {
      if (grid[i][j] == target) return {i, j};
    }
  }
  return {-1, -1};
}

pair<int, int> get_corner2(vector<vector<int>> &grid, int target) {
  for (int i = grid[0].size() - 1; i >= 0; --i) {
    for (int j = grid[0].size() - 1; j >= 0; --j) {
      if (grid[i][j] == target) return {i, j};
    }
  }
  return {-1, -1};
}

set<int> search_intruders(vector<vector<int>> &grid, int x1, int y1, int x2, int y2, int normal) {
  set<int> result = {};
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      if (grid[i][j] != normal) result.insert(grid[i][j]);
    }
  }

  return result;
}

int main() {
  freopen("art.in", "r", stdin);
  /*freopen("art.out", "w", stdout);*/

  int n = nxt();


  vector<vector<int>> grid(n, vector<int>(n, 0));
  set<int> res = {};

  for (int i = 0; i < n; ++i) {
    string line;
    cin >> line;  // Read each line as a string
    for (int j = 0; j < n; ++j) {
      // Convert each character to an integer and store in the grid
      grid[i][j] = line[j] - '0';
      res.insert(grid[i][j]);
    }
  }

  res.erase(0);


  for (int i = 1; i <= 9; ++i) {
    // Find the leftmost corner of whatever there is here. If it doesn't appear,
    // skip it.
    pair<int, int> a = get_corner1(grid, i);
    if (a == make_pair(-1, -1)) continue;
    pair<int, int> b = get_corner2(grid, i);
    int x1 = min(a.first, b.first);
    int x2 = max(a.first, b.first);
    int y1 = min(a.second, b.second);
    int y2 = max(a.second, b.second);
    set<int> result = search_intruders(grid, x1, y1, x2, y2, i);
    for (int x : result) {
      res.erase(x);
    }
  }

  cout << res.size() << endl;

  return 0;
}
