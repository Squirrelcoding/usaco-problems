#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int x; cin >> x; return x;
}

int calculate_rightmost(vector<int>& nums, int start, int start_index) {
  int total = 0;
  int radius = 1;
  int i = start;
  int upper_limit = nums[nums.size() - 1];

  ++start_index;

  // Count all of the bales to the right of the rightmost bale that are still within N.
  while (i <= upper_limit) {

    // Check if there are any numbers
    int original_total = total;
    int rightmost = i + 1;
    for (int j = i + 1; j <= i + radius; ++j) {
      cout << "R: Exploding at i=" << i << " with radius=" << radius << endl;
      if (start_index > nums.size()) break;

      // Haybale reached 
      if (nums[start_index] == j) {
        i = j;
        total += 1;
        ++start_index;
      }
    }
    if (original_total == total) break;
    radius += 1;
    i = rightmost;
  }

  return total;
}

int calculate_leftmost(vector<int>& nums, int start, int start_index) {
  int total = 0;
  int radius = 1;
  int i = start;

  --start_index;

  // Count all of the bales to the left of the leftmost bale that are still within N.
  while (0 <= i) {
    int original_total = total;
    int leftmost = i - 1;
    for (int j = i - 1; i - radius <= j; --j) {
      cout << "L: Exploding at i=" << i << " with radius=" << radius << endl;
      if (0 > start_index) break;
      // If a haybale is present at j.
      if (nums[start_index] == j) {
        total += 1;
        --start_index;
        leftmost = j;
      }
    }
    if (original_total == total) break;
    radius += 1;
    i = leftmost;
  }
  return total;
}

int main() {
  freopen("angry.in", "r", stdin);
  int n = nxt();
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = nxt();
  }

  sort(all(nums));


  int max_score = 0;

  for (int candidate = 0; candidate < n; ++candidate) {
    int left = calculate_leftmost(nums, nums[candidate], candidate);
    int right = calculate_rightmost(nums, nums[candidate], candidate);

    cout << nums[candidate] << " " << left << ", " << right << endl;
    max_score = max(max_score, 1 + left + right);
  }

  cout << max_score << endl;

  return 0;
}
