#include <bits/stdc++.h>

using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

#define all(x) begin(x), end(x)

// Returns the next integer in the simulation
int next_int(int starting_point_idx, vector<int> &nums) {
  if (nums.size() == 1) return 0;
  if (starting_point_idx == 0) return 1;
  if (starting_point_idx == nums.size() - 1) return starting_point_idx - 1;

  int left = nums[starting_point_idx - 1];
  int right = nums[starting_point_idx + 1];
  int x = nums[starting_point_idx];

  if (abs(x - right) < abs(x - left)) {
    return starting_point_idx + 1;
  }
  return starting_point_idx - 1;
}

// Simulates the path that the ball will take
set<int> simulate_path(int starting_point, vector<int> &nums) {
  set<int> result = {starting_point};
  int idx = starting_point;
  int prev_size = 0;
  while (result.size() != prev_size) {
    prev_size = result.size();
    idx = next_int(idx, nums);  
    result.insert(idx);
  }

  return result;
}

bool isProperSubset(const std::set<int>& A, const std::set<int>& B) {
    return A.size() < B.size() && std::includes(B.begin(), B.end(), A.begin(), A.end());
}

int main() {
  freopen("hoofball.in", "r", stdin);
  freopen("hoofball.out", "w", stdout);
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);
  sort(all(nums));
  set<set<int>> superset = {};

  for (int i = 0; i < n; ++i) {
    superset.insert(simulate_path(i, nums));
  }
  set<set<int>> to_be_removed = {};

  for (set<int> a: superset) {
    for (set<int> b: superset) {
      if (isProperSubset(a, b)) to_be_removed.insert(a);
    }
  }
  for (set<int> a : to_be_removed) superset.erase(a);

  cout << superset.size() << endl;
  return 0;
}
