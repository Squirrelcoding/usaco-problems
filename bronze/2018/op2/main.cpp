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
    int a = 0; int b = 0;
    cin >> a; cin >> b;
    demands[a] = b;
    res[b] = a;
  }

  for (int candidate = 1; candidate <= n; ++candidate) {

    // Set in the candidate
    res[candidate] = 1;
    // Since the demands are already filled in we just have to fill in the
    // social hierarchy
    int j = 1;
    int count = 0;
    while (count < k) {
      if (res[j] == 0) {
        res[j] = social_h[count];
        ++count;
      }
      ++j;
    }

    // Check if it's consistent by checking:
    // 1. The social hierarchy is satisfied
    // 2. There is only one instance of everything

  }


  return 0;
}
