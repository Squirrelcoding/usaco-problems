#include <bits/stdc++.h>

using namespace std;

int main() {
  /*freopen("input", "r", stdin);*/
  int n; cin >> n;
  int x; cin >> x;
  map<int, pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    if (s.count(y) != 0) {
      s[y] = {s[y].first, i};
    } else {

    s[y] = {i, -1};
    }
  }

  bool found = false;
  for (auto it = s.begin(); it != s.upper_bound(x); it++) {

    // If x-n is also a member
    if (s.count(x - it->first)) {
      auto indices = it->second;

      // If x == it->first and they are two double instances
      if (2*it->first == x) {
        if (indices.second != -1) {
          cout << indices.first + 1<< " " << indices.second + 1 << endl;
        } else {
          continue;
        }
      } else {
        cout << it->second.first + 1<< " " << s[x - it->first].first + 1 << endl;
      }
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
