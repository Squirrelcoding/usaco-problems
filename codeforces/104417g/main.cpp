#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("input", "r", stdin);
  int t = nxt();
  for (int _i = 0; _i < t; ++_i) {
    int n = nxt();
    vector<int> nums(n);
    generate(all(nums), nxt);

    // Form an adjacency list
    map<int, vector<int>> adjacency_list;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (i - j == nums[i] - nums[j]) {
          if (adjacency_list.count(i)) {
            adjacency_list[i].push_back(j);
          } else {
            adjacency_list[i] = {j};
          }
        }
      }
    }

    for (auto p : adjacency_list) {
      cout << p.first << ": ";
      for (int i : p.second) {
        cout << i << " ";
      }
      cout << endl;
    }

    cout << "==========================" << endl;

    set<int> visited_nodes;
    
    int result = 0;
    for (auto p : adjacency_list) {
      if (visited_nodes.count(p.first)) continue;
      int a = INT_MIN;
      int b = INT_MIN;
      for (int i : p.second) {
        visited_nodes.insert(i);
        if (nums[i] > b) {
          if (nums[i] > a) {
            b = a;
            a = nums[i];
          } else {
            b = nums[i];
          }
        }
      }
      result += max(0, a + b);
    }
    cout << result << endl;
  }
  return 0;
}
