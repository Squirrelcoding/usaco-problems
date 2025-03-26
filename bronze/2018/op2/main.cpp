#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("milkorder.in", "r", stdin);
  /*freopen("milkorder.out", "w", stdout);*/
  int n = nxt();
  int m = nxt();
  int k = nxt();

  vector<int> social_h;
  for (int i = 0; i < m; ++i) {
    int num = nxt();
    social_h.push_back(num);
  }

  unordered_map<int, int> demands;
  vector<int> res(n + 1);

  for (int i = 0; i < k; ++i) {
    int a = nxt();
    int b = nxt();
    demands[a] = b;
    res[b] = a;
  } 

  int most_recent = social_h.back();
  for (int i = n; i >= 1; --i) {
    if (social_h.size() == 0) break;
    if (demands.count(most_recent)) {
      i = demands[most_recent];
    }
    res[i] = most_recent;
    social_h.pop_back();
    most_recent = social_h.back();
  }

  // Keep going until we reach a 0
  int first_free_spot = 1;
  while (res[first_free_spot] != 0) {
    first_free_spot++;
  }

  /*for (int a : res) cout << a << ", ";*/
  /*cout << endl;*/

  cout << first_free_spot << endl;

  return 0;
}
