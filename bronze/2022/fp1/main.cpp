#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  // Get the sum of the entries first.
  int sum = accumulate(nums.begin(), nums.end(), 0);
  int max = *max_element(nums.begin(), nums.end());

  // Get the divisors of `sum` 
  vector<int> divisors;
  for (int i = 1; i <= sum; ++i) {
    if (sum % i == 0 && i >= max) {
      divisors.push_back(i);
    }
  }

  // Sort the divisors so that we start with the smallest.
  sort(divisors.begin(), divisors.end());



  // Run through the array to see if it's possible to form the sum using a two-pointer method.
  // It will only fail if we cannot make a cumsum equal to d. 
  for (int d : divisors) {

    int i = 0; int j = 0;

    int cumsum = 0;
    bool possible = true;
    while (j < nums.size()) {
      if (cumsum > d) {
        possible = false;
        break;
      }
      if (cumsum == d) {
        cumsum = 0;
        i = j;
      }
      cumsum += nums[j];
      ++j;
    } 

    if (possible) {
      return nums.size() - sum / d;
    }
  }

  return 0;
}

int main() {
  int t;
  cin >> t;

  vector<vector<int>> inputs;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int j = 0; j < n; ++j) {
      int k;
      cin >> k;
      nums[j] = k;
    }
    inputs.push_back(nums);
  }


  for (auto k : inputs) {
    cout << solve(k) << endl;
  }

}
