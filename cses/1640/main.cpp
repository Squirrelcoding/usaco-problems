#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input", "r", stdin);
  int n; cin >> n;
  int x; cin >> x;
  map<int, int> s;
  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;
    s[y] = i;
  }

  bool found = false;
  for (auto it = s.begin(); it != s.upper_bound(x); it++) {
    if (s.count(x - it->first)) {
      if (it->second == s[x-it->first]) continue;
      cout << it->second + 1<< " " << s[x - it->first] + 1 << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
