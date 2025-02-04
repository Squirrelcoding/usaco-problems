#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  string input;
  cin >> input;

  unordered_map<char, pair<int, int>> coordinates;


  for (int i = 0; i < 52; ++i) {
    if (coordinates.find(input[i]) == coordinates.end()) {
      coordinates[input[i]].first = i;
    } else {
      coordinates[input[i]].second = i;
    }
  }

  int count = 0;

  // Loop thorugh each of the chars and find the other 
  for (char c = 'A'; c <= 'Z'; ++c) {
    for (char d = 'A'; d <= 'Z'; ++d) {
      if (c == d) {
        continue;
      }
      // Check if the first one is between the two endpoints of the `c` cow and the other one is outside.
      if (coordinates[c].first < coordinates[d].first && coordinates[d].first < coordinates[c].second && coordinates[c].second < coordinates[d].second) {
        ++count; 
      }
    }
  }
  
  cout << count << endl;
  return 0;
}
