#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  /*freopen("input", "r", stdin);*/
  int n = nxt();
  cin.ignore(2); // since q=0 in all inputs
                 //
  vector<int> nums(n);
  generate(all(nums), nxt);


  unordered_map<int, pair<int, int>> intervals;
  unordered_map<int, int> block_names;

  vector<pair<int, int>> final_intervals;

  for (int i = 0; i < n; ++i) {
    if (intervals.count(nums[i]) == 0) {
      intervals[nums[i]] = {i, i};
    } else {
      intervals[nums[i]].second = i;
    }
  }


  int p1 = intervals[nums[0]].second;
  int p2 = intervals[nums[0]].second;

  int end_of_previous_block = 0;
  block_names[p1] = nums[p1];


  while (p1 < n) {
    while (p2 > end_of_previous_block - 1) {
      // break
      auto interval = intervals[nums[p2]];
      if (interval.second > p1) {
       
        p1 = interval.second;
        p2 = p1;
      }
      --p2;
    }

    final_intervals.push_back({end_of_previous_block, p1});
    end_of_previous_block = p1 + 1;
    
    // Start a new block
    p1 += 1;
    p2 = p1;
  }

  int grand_sum = 0;

  // Form the block names for each entry
  unordered_map<int, int> frequencies;

  for (const auto& entry : final_intervals) {
    for (int i = entry.first; i <= entry.second; ++i) {
      frequencies[nums[i]]++; 
    }
    auto maxIt = std::max_element(all(frequencies),
        [](const auto& p1, const auto& p2) {
            return p1.second < p2.second;
        });
    
    grand_sum += (entry.second - entry.first + 1) - maxIt->second;

    // Get the most common one
    frequencies.clear();
  }

  cout << grand_sum << endl;

  return 0;
}
