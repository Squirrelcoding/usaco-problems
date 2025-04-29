#include <bits/stdc++.h>
using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

set<int> search_intruders(vector<vector<int>> &grid, int x1, int y1, int x2, int y2, int normal) {
  set<int> result;
  for (int y = y1; y <= y2; ++y) {
    for (int x = x1; x <= x2; ++x) {
      if (grid[y][x] != normal) result.insert(grid[y][x]);
    }
  }
  return result;
}

int main() {
  freopen("art.in", "r", stdin);
  freopen("art.out", "w", stdout);

  int n = nxt();
  vector<vector<int>> grid(n, vector<int>(n));
  set<int> remaining;

  // Initialize bounding box trackers
  vector<int> minX(10, n), maxX(10, -1), minY(10, n), maxY(10, -1);

  for (int y = 0; y < n; ++y) {
    string line; cin >> line;
    for (int x = 0; x < n; ++x) {
      int val = line[x] - '0';
      grid[y][x] = val;
      if (val == 0) continue;
      remaining.insert(val);
      minX[val] = min(minX[val], x);
      maxX[val] = max(maxX[val], x);
      minY[val] = min(minY[val], y);
      maxY[val] = max(maxY[val], y);
    }
  }

  for (int color = 1; color <= 9; ++color) {
    if (minX[color] > maxX[color]) continue; // Color not found
    set<int> intruders = search_intruders(grid, minX[color], minY[color], maxX[color], maxY[color], color);
    for (int intruder : intruders) {
      remaining.erase(intruder);
    }
  }

  cout << remaining.size() << endl;
  return 0;
}
