#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("taming.in", "r", stdin);
  freopen("taming.out", "w", stdout);
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);

  // For positive integers, fill in the ones leading up to it.
  for (int i = 0; i < n; ++i) {
    if (nums[i] > 0) {
      for (int j = 1; j <= nums[i]; ++j) {
        nums[i - j] = nums[i] - j;
      }
    }
  }
  nums[0] = 0;

  // Verify that it's possible in the first place.
  // A sequence is only unsolvable iff BEFORE we place everything in, we already have an invalid thing.
  vector<int> copy = nums;
  bool valid = true;
  for (int i = 0; i < n; ++i) {
    if (copy[i] == -1) copy[i] = 0;
  }

  // Check if it's all good
  for (int i = 0; i < n - 1; ++i) {
    if (copy[i+1] != 0 && copy[i+1] != copy[i] + 1) valid = false;
  }

  if (!valid) {
    cout << -1 << endl;
    return 0;
  }

  int num_zeroes = 0;
  // Count the number of 0's
  for (int i = 0; i < n; ++i) {
    if (nums[i] == 0) ++num_zeroes;
  }

  int negative_ones = 0;
  // Count the number of -1's
  for (int i = 0; i < n; ++i) {
    if (nums[i] == -1) ++negative_ones;
  }

  cout << num_zeroes << " " << num_zeroes + negative_ones << endl;

  return 0;
}

// How do we check if it's invalid?
// Every possible combination of entering numbers does not lead to a good list
// A good list is one where we start with 0 and the next element is either 0 or n+1
// Fill in all with zeroes and check if 
