#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("milkorder.in", "r", stdin);
  freopen("milkorder.out", "w", stdout);
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
  vector<int> res_copy(n + 1);
  for (int i = 0; i < k; ++i) {
    int a = 0; int b = 0;
    cin >> a; cin >> b;
    demands[a] = b;
    res[b] = a;
    res_copy[b] = a;
  }

  set<int> instances;
  for (int candidate = 1; candidate <= n; ++candidate) {
    if (res[candidate] != 0) continue;
    // Set in the candidate
    res[candidate] = 1;
    // Since the demands are already filled in we just have to fill in the
    // social hierarchy
    int j = 1;
    int count = 0;
    while (count <= k) {
      if (res[j] == 0 || (res[j] == social_h[count] && demands.count(res[j]) != 0)) {
        res[j] = social_h[count];
        ++count;
      }
      ++j;
    }
    /*cout << "candidate = " << candidate << endl;*/
    /*for (int x : res) cout << x << " ";*/
    /*cout << endl;*/

    // Check if it's consistent by checking:
    // 1. There is only one instance of everything
    // 2. The social hierarchy is satisfied
    bool cont = false;
    for (int num : res) {
      if (num == 0) continue;
      if (instances.count(num) != 0) {
        cont = true;
        break;
      }
      instances.insert(num);
    }

    /*cout << "64" << endl;*/
    if (cont) {
      res = res_copy;
      instances = {};
      continue;
    }

    /*cout << "71" << endl;*/
    int social_ptr = 0;
    for (int i = 1; i <= n; ++i) {
      if (res[i] == social_h[social_ptr]) {
        social_ptr++;
      }
    }

    if (social_ptr < k) {
      instances = {};
      res = res_copy;
      continue;
    }

    // It has been found!!
    auto it = find(all(res), 1);
    int index = distance(res.begin(), it);
    cout << index << endl;
    break;
  }


  return 0;
}
