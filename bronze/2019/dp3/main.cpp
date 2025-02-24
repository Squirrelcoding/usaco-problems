#include <bits/stdc++.h>

using namespace std;

map<string, int> cow_index = {
    {"Beatrice", 0},
    {"Belinda", 1},
    {"Bella", 2},
    {"Bessie", 3},
    {"Betsy", 4},
    {"Blue", 5},
    {"Buttercup", 6},
    {"Sue", 7}
};


bool is_valid(vector<pair<int, int>>& constraints, vector<int> cows) {

  // Loop through each constraint and check if it's satisfied
  for (auto constraint : constraints) {
    int a = -1; int b = -1;
    for (int i = 0; i < cows.size(); ++i) {
      if (cows[i] == constraint.first) {
        a = i;
      }
      if (cows[i] == constraint.second) {
        b = i;
      }
    }
    if (a == -1 || b == -1 || abs(a-b) != 1) {
      return false;
    }
  }
  
  return true;
}

// Checks whether a comes before b.
//
// b will ONLY come before a if 
bool compareSolutions(vector<int>& a, vector<int>& b) {
  for (int i = 0; i < 8; i++) {
    if (b[i] < a[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  int n;
  cin >> n;
  cin.ignore();

  // Read the lines into a pair of integers
  vector<pair<int, int>> constraints;
  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);

    string word;
    istringstream iss(line);
    vector<string> words;

    while (iss >> word) {
      words.push_back(word);
    }

    int first_cow = cow_index[words[0]];
    int second_cow = cow_index[words[words.size() - 1]];

    constraints.push_back(make_pair(min(first_cow, second_cow), max(first_cow, second_cow)));
  }

  vector<int> v;
  for (int i = 0; i < 8; ++i) v.push_back(i);

  vector<vector<int>> valid_solutions;
  // Loop through all of the combinations
  do {
    if (is_valid(constraints, v)) {
      valid_solutions.push_back(v);
    }

  } while (next_permutation(v.begin(), v.end()));


  // Order the valid solutions and get the "smallest" one;
  sort(valid_solutions.begin(), valid_solutions.end());

  auto first = valid_solutions[0];

  vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
  for (auto x : first) {
    cout << cows[x] << endl;
  }
 
  return 0;
}


