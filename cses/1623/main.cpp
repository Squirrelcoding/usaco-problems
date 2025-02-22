#include<bits/stdc++.h>
#include <cmath>

using namespace std;

int solve(int n, const vector<int>& numbers, int index, int sum_a, int sum_b) {
  if (index == n) {
    return abs(sum_a - sum_b);
  }
  
  // Add the number of the index to sum_a
  int option1 = solve(n, numbers, index+1, sum_a + numbers[index], sum_b);
  int option2 = solve(n, numbers, index+1, sum_a, sum_b + numbers[index]);

  return min(option1, option2);
}

int main() {
  int n;
  cin >> n;

  vector<int> numbers(n);

  int target = accumulate(numbers.begin(), numbers.end(), 0) / 2;

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    numbers[i] = k;
  }

  // The goal is to get as close to the target as possible
  cout << solve(n, numbers, 0, 0, 0) << endl; 


  return 0;
}
