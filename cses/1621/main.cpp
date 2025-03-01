#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int nxt() {
  int x;
  cin >> x;
  return x;
}

int main() {
  int n = nxt();
  int nums[n];

  for (int i = 0; i < n; ++i) {
    nums[i] = nxt();
  }

  sort(nums, nums + n);

  int count = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i + 1] != nums[i]) {
      ++count;
    }
  }

  cout << count << endl;
  return 0;
}
