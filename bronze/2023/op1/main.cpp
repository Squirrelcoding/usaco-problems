#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("input", "r", stdin);
  int n = nxt();
  string s;
  cin >> s;

  int existing_pairs = 0;

  // Start by counting existing pairs
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i+1] && s[i] != 'S') ++existing_pairs;
  }

  set<int> megaset;
  megaset.insert(existing_pairs);

  // Find the F-blocks
  vector<pair<int, int>> f_blocks;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'F') {
      int j = i + 1;
      while (j < n && s[j] == 'F') ++j;
      f_blocks.push_back({i, j - 1});
      i = j;
    }
  }


  for (auto f_block : f_blocks) {
    int start = f_block.first;
    int end = f_block.second;
    int length = end - start + 1;
    cout << start << " " << end << endl;

    set<int> megaset_copy = megaset;

    // Case I: All F's
    if (start == 0 && end == n-1) {
      for (int x : megaset) {
        for (int i = 0; i < length; ++i) megaset_copy.insert(x + i);
      }
    }
    // Case II: AF
    else if (end == n-1) {
      for (int x : megaset_copy) {
        for (int i = 0; i <= length; ++i) megaset_copy.insert(x + i);
      }
    }
    // Case III: FA
    else if (start == 0) {
      for (int x : megaset_copy) {
        for (int i = 0; i <= length; ++i) megaset_copy.insert(x + i);
      }
    }
    // Case IV: AFA
    else if (s[start - 1] == s[end + 1]) {
      if (length % 2 == 0) {
        for (int x : megaset_copy) {
          for (int i = 0; i <= length + 1; i += 2) megaset.insert(x + i);
        }
      } else {
        for (int x : megaset_copy) {
          for (int i = 1; i <= length + 1; i += 2) megaset.insert(x + i);
        }
      }
    }
    // Case V: AFB
    else {
      if (length % 2 == 0) {
        for (int x : megaset_copy) {
          for (int i = 0; i <= length; i += 2) megaset.insert(x + i);
        }
      } else {
        for (int x : megaset_copy) {
          for (int i = 1; i <= length; i += 2) megaset.insert(x + i);
        }
      }
    }
  }

  cout << megaset.size() << endl;
  for (int x : megaset) {
    cout << x << endl;
  }
}
