#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("swap.in", "r", stdin);
  int n = nxt();
  int k = nxt();
  int a1 = nxt() - 1;
  int a2 = nxt() - 1;
  int b1 = nxt() - 1;
  int b2 = nxt() - 1;

  vector<int> nums;
  for (int i = 0; i < n; ++i) {nums.push_back(i);}

  // First apply the A swaps
  for (int i = a1; i <= (a2 + a1) / 2; ++i) {
    int temp = nums[i];
    int swapped_index = a1 + a2 - i;
    nums[i] = nums[swapped_index];
    nums[swapped_index] = temp;
  }



  // Then apply the B swaps
  for (int i = b1; i <= (b2 + b1) / 2; ++i) {
    int temp = nums[i];
    int swapped_index = b1 + b2 - i;
    nums[i] = nums[swapped_index];
    nums[swapped_index] = temp;
  }

  vector<vector<int>> map = {};

  // Make an adjacency list.
  for (int n : nums) {
    cout << "processing " << n << "..." << endl;
    bool new_val = true;
    for (auto s : map) {
      if (find(all(s), n) != s.end()) {
        cout << n << " is in a set." << endl;
        new_val = false;
      }
    }
    if (!new_val) continue;
    cout << n << " belongs to a new set!" << endl;

    // Traverse
    int i = n;
    vector<int> new_set = {n};
    while (nums[i] != n) {
      new_set.push_back(nums[i]);
      i = nums[i];
    }
    map.push_back(new_set);
  }

  vector<int> result(n);

  for (auto s : map) {
    for (int n : s) {
      result[n] = s[(n + k) % s.size()];
    }
  }

  for (int n : result) {

  }

  return 0; 
}
