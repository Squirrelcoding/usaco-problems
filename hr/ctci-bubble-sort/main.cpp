#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
  int n;
  cin >> n;
  int steps = 0;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    int k; cin >> k; nums[i] = k;
  }


  sort(all(nums));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n-1; ++j) {
      if (nums[j] > nums[j+1]) {
        // Swap
        int temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;
        ++steps;
      }
    }
  }

  cout << "Array is sorted in " << steps << " swaps." << endl;
  cout << "First element: " << nums[0] << endl;
  cout << "Last element: " << nums[n - 1] << endl;

  return 0;
}
