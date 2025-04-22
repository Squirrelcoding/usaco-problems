#include <bits/stdc++.h>

using namespace std;


#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

pair<int, int> get_corner1(vector<vector<int>> &grid, int target) {
  for (int y = 0; y < grid[0].size(); ++y) {
    for (int x = grid[0].size() - 1; x >= 0; --x) {
      if (grid[y][x] == target) return {x, y};
    }
  }
  return {-1, -1};
}

pair<int, int> get_corner2(vector<vector<int>> &grid, int target) {
  for (int y = grid[0].size() - 1; y >= 0; --y) {
    for (int x = 0; x < grid[0].size(); ++x) {
      if (grid[y][x] == target) return {x, y};
    }
  }
  return {-1, -1};
}


pair<int, int> get_corner3(vector<vector<int>> &grid, int target) {
  for (int y = grid[0].size() - 1; y >= 0; --y) {
    for (int x = grid[0].size() - 1; x >= 0; --x) {
      if (grid[y][x] == target) return {x, y};
    }
  }
  return {-1, -1};
}


pair<int, int> get_corner4(vector<vector<int>> &grid, int target) {
  for (int y = 0; y < grid[0].size(); ++y) {
    for (int x = 0; x < grid[0].size(); ++x) {
      if (grid[y][x] == target) return {x, y};
    }
  }
  return {-1, -1};
}

set<int> search_intruders(vector<vector<int>> &grid, int x1, int y1, int x2, int y2, int normal) {
  set<int> result = {};
  for (int i = x1; i <= x2; ++i) {
    for (int j = y1; j <= y2; ++j) {
      if (grid[j][i] != normal) result.insert(grid[j][i]);
    }
  }

  return result;
}

int main() {
  freopen("art.in", "r", stdin);
  freopen("art.out", "w", stdout);

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
    pair<int, int> c = get_corner3(grid, i);
    pair<int, int> d = get_corner4(grid, i);
    int x1 = min(a.first, min(b.first, min(c.first, d.first)));
    int x2 = max(a.first, max(b.first, max(c.first, d.first)));
    int y1 = min(a.second, min(b.second, min(c.second, d.second)));
    int y2 = max(a.second, max(b.second, max(c.second, d.second)));
    /*cout << i << " | x1 = " << x1 << ", x2 = " << x2 << " | y1 = " << y1 << ", y2 = " << y2 << endl;*/
    set<int> result = search_intruders(grid, x1, y1, x2, y2, i);
    for (int x : result) {
      res.erase(x);
    }
  }

  cout << res.size() << endl;

  return 0;
}
