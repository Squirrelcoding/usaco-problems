#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("gymnastics.in", "r", stdin); 
  freopen("gymnastics.out", "w", stdout); 
  int n; int k;
  cin >> n >> k;
  
  vector<vector<int>> rankings;

  for (int i = 0; i < n; ++i) {
    rankings.push_back({});
    for (int j = 0; j < k; ++j) {
      int input;
      cin >> input;
      rankings.back().push_back(input);
    } 
  }

  // Ok so how the hell do we do this? Well, the theme is just brute force. We have to brute force our way.
  // The question is, HOW do we brute force it?
  // Loop through every possible pair and check if it's consistent.

  int consistent_pairs = 0;

  for (int i = 1; i <= k; ++i) {
    for (int j = i + 1; j <= k; ++j) {
      // Check if (i, j) is consistent.
      int better;
      int worse;
      auto first_sequence = rankings[0];
      for (int m = 0; m < k; ++m) {
        if (first_sequence[m] == i) {
          better = i;
          worse = j;
          break;
        }
        if (first_sequence[m] == j) {
          better = j;
          worse = i;
          break;
        }
      }


      bool is_consistent = true;
      for (int m = 1; m < n; ++m) {
        auto sequence = rankings[m]; 
        // Check if worse comes before better, in which case it is NOT consistent.
        auto worse_index = find(sequence.begin(), sequence.end(), worse);
        auto better_index = find(sequence.begin(), sequence.end(), better);
        if (worse_index < better_index) {
          is_consistent = false;
          break;
        }
      }

      if (is_consistent) {
        ++consistent_pairs;
      }

    }
  }

  cout << consistent_pairs << endl;

  return 0;
}
