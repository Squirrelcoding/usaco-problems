#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int> quadcount;

int count_cows(int a, int b, vector<pair<int, int>>& coordinates) {
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    
    for (auto& cow : coordinates) {
        int x = cow.first, y = cow.second;
        if (x < a && y > b) q1++; // Quadrant I
        else if (x > a && y > b) q2++; // Quadrant II
        else if (x > a && y < b) q3++; // Quadrant III
        else if (x < a && y < b) q4++; // Quadrant IV
    }
    
    return max({q1, q2, q3, q4});
}


int main() {
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);
  int n; int b;
  cin >> n >> b;

  vector<pair<int, int>> coordinates;

  for (int i = 0; i < n; ++i) {
    int a; int b;
    cin >> a >> b;
    coordinates.push_back(make_pair(a, b));
  }

  int res = INT_MAX;

  for (auto coordinate : coordinates) {
    int x = coordinate.first;
    int y = coordinate.second;
    auto candidate1 = count_cows(x - 1, y - 1, coordinates);
    auto candidate2 = count_cows(x - 1, y + 1, coordinates);
    res = min({res, candidate1, candidate2});
  }

  cout << res << endl;


  return 0;
}
