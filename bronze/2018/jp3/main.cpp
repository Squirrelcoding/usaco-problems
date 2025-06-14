#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <iterator>
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int find_anamoly(vector<int>& nums) {
  int length = nums.size();

  // Edge case: only 2 numbers
  if (length == 2) {
    if (nums[1] < nums[0]) {
      return 0;
    }
    return -1;
  }

  // Check first element
  if (nums[0] > nums[1]) return 0; 

  // Check elements in between
  for (int i = 1; i < length - 1; ++i) {
    if (
        (nums[i] < nums[i - 1] && nums[i] < nums[i + 1] && nums[i - 1] <= nums[i + 1]) || 
        (nums[i] > nums[i + 1] && nums[i] > nums[i - 1] && nums[i - 1] <= nums[i + 1])
      ) {
      return i;
    }
  }

  // Check last element
  if (nums[length - 1] < nums[length - 2]) return length - 1;

  return -1;
}


int main() {
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);
  /**/
  /*for (int x : nums) {*/
  /*  cout << x << " ";*/
  /*}*/
  /*cout << endl;*/
  /**/
  int i = find_anamoly(nums);
  
  /*cout << "i = " << i << endl;*/

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
    while (j >= 0 && nums[j] > nums[i]) {
      j--;
      if (nums[j] != nums[j + 1]) result++;
    }
    cout << result << endl;
  }

  return 0;
}
