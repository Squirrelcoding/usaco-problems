#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
    
  int n; cin >> n;
  string s; cin >> s;

  int k = n;
  while (k >= 0) {
    vector<int> window(k);
    set<vector<int>> substrings;

    // i is the starting index for the current substring
    for (int i = 0; i < n - k + 1; ++i) {
      for (int j = 0; j < k; ++j) window[j] = s[i + j];
      substrings.insert(window);
    }

    // If substrings.size() < n-k then there are at least two equal subsequences,
    // so we must stop.
    if (substrings.size() != n - k + 1) {
      break;
    } else {
      k -= 1;
    }
  }
  cout << k + 1 << endl;
  return 0;
}
