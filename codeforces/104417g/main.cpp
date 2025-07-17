#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  int t = nxt();
  for (int _i = 0; _i < t; ++_i) {
    int n = nxt();
    vector<int> nums(n);
    generate(all(nums), nxt);

    // Form an adjacency matrix  
    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i - j == nums[i] - nums[j]) {
          adjacency_matrix[i][j] = 1;
        }
      }
    }

    set<int> visited_graphs;


  }
  return 0;
}
