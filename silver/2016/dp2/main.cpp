#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);
  int n; cin >> n;
  map<pair<string, string>, long long> codes;

  string city_name;
  string state_code;

  long long pairs = 0;

  for (int i = 0; i < n; ++i) {
    cin >> city_name; cin >> state_code;
    string s = city_name.substr(0, 2);
    pair<string, string> p = {s, state_code};
    codes[p]++;
  }

  for (auto p : codes) {
    // q is {STATE CODE, CITY}
    pair<string, string> q = {p.first.second, p.first.first};

    if (codes.count(q)) {
      pairs += codes[q];
    }
  }

  cout << pairs / 2 << endl;

  return 0;
}

// MIAMI FL
// MINNESOTA FL
// FLINT MI
// FLOP MI
