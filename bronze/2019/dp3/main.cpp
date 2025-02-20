#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // or use boost::hash_combine
    }
};

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


  vector<vector<int>> orders;
  orders.push_back({constraints[0].first});

  auto next_pair = constraints[0];
  while (constraints.size() > 0) {
    vector<int> next_order;
    next_order.push_back(constraints[0].first);
    vector<pair<int, int>> deleted;
    // Try to find other pairs with next_pair.second as the first entry.
    for (auto constraint : constraints) {
      if (constraint == next_pair) continue;
      if (next_pair.second == constraint.first) {
        next_order.push_back(constraint.first);
        deleted.push_back(constraint);
      }
    }
    orders.push_back(next_order);

    // Delete all of these guys
    for (auto x : deleted) {
      constraints.erase(remove(constraints.begin(), constraints.end(), x), constraints.end());
    }

  }

  return 0;
}


