#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<int, int>> coordinates(n);

  for (int i = 0; i < n; ++i) {
    int x; int y;
    cin >> x >> y;
    coordinates[i] = make_pair(x, y);
  }

  int max_area = INT_MIN;

  // How the hell do we find the maximum? 
  for (auto coordinate : coordinates) {

    // p1 is the point that is furthest on the x-axis relative to coordinate.
    pair<int, int> p1 = coordinate;

    // p2 is the point that is furthest on the y-axis relative to coordinate.
    pair<int, int> p2 = coordinate;

    for (auto other_coordinate : coordinates) {
      if (coordinate.second == other_coordinate.second) {
        if (abs(coordinate.first - p1.first) < abs(coordinate.first - other_coordinate.first)) {
          p1 = other_coordinate;
        }
      }

      if (coordinate.first == other_coordinate.first) {
        if (abs(coordinate.second - p2.second) < abs(coordinate.second - other_coordinate.second)) {
          p2 = other_coordinate;
        }
      }
    }

    max_area = max(max_area, abs(coordinate.first - p1.first) * abs(coordinate.second - p2.second));
  }


  cout << max_area << endl;

  return 0;
}
