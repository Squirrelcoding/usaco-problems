#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n;
  cin >> n;
  return n;
}

int main() {
  // Do a stars and bars search that's like O(n^2) time complexity.
  int n = nxt();

  vector<int> nums(2*n);
  for (int i = 0; i < 2*n; ++i) {
    nums[i] = nxt();
  }

  // Sort the numbers
  sort(all(nums));
  // Brute force all of the possible combinations using the given stars and bars thing

  int min_sum = INT_MAX;

  for (int p1 = 0; p1 < 2*n; ++p1) {
    for (int p2 = p1; p2 < 2*n; ++p2) {
      int s = 0;
      int current = 0;
      int a = 0;
      int b = 0;
      for (int i = 0; i < 2*n; ++i) {
        if (i == p1 || i == p2) {
          continue;
        }
        if (current == 0) {
          a = nums[i];
        } else {
          b = nums[i];
          s += abs(a-b);
        }
        current += 1;
        current %= 2;
      }
      min_sum = min(min_sum, s);
    }
  }

  cout << min_sum << endl;
  return 0;
}
