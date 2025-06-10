#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int find_anomaly(vector<int>& nums) {
    if (nums[0] > nums[1]) return 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            return i + 1; // Return the index of the out-of-order element
        }
    }
    return -1; // Return -1 if the list is in order
}

int main() {
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);

  int i = find_anomaly(nums);

  // If the list is already in order
  if (i == -1) {
    cout << "0" << endl;
    return 0;
  }

  // If the true position of the value comes after i
  // Ex: 10 20 30 500 40
  //               i
  if (nums[i + 1] < nums[i]) {
    int result = 0;
    int j = i + 1;
    while (j < n && nums[j] < nums[i]) {
      j++;
      if (nums[j] != nums[j - 1]) result++;
    }
    cout << result << endl;
  } 
  // If the true position of the value comes before i
  // Ex: 10 20 30 5 40
  //              i
  else {
    int result = 0;  
    int j = i - 1;
    while (j > 0  && nums[j] > nums[i]) {
      j--;
      if (nums[j] != nums[j + 1]) result++;
    }
    cout << result << endl;
  }

  return 0;
}
