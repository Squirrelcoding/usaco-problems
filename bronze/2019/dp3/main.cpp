#include <bits/stdc++.h>

using namespace std;


bool is_valid(vector<pair<int, int>>& constraints, vector<int> cows) {

  // Loop through each constraint and check if it's satisfied
  for (auto constraint : constraints) {
    int a; int b;
    for (int i = 0; i < cows.size(); ++i) {
      if (cows[i] == constraint.first) {
        a = i;
      }
      if (cows[i] == constraint.second) {
        b = i;
      }
      if (abs(a-b) != 1) {
        return false;
      }
    }
  }
  
  return true;
}

int main() {
  freopen("lineup.in", "r", stdin);

  int n;
  cin >> n;
  cin.ignore();

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
  for (int i = 0; i < n; ++i) v.push_back(i);

  vector<vector<int>> valid_solutions;
  // Loop through all of the combinations
  do {
    if (is_valid(constraints, v)) {
      valid_solutions.push_back(v);
    }

  } while (next_permutation(v.begin(), v.end()));


  // Order the valid solutions and get the "smallest" one;
 
  return 0;
}


