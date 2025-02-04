#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;


struct entry {
  int day;
  string name;
  int amount;
};

bool compare_days(const entry& a, const entry& b) {
  return a.day < b.day; 
}


vector<string> top_cows(unordered_map<string, int>& entries) {
  vector<string> result;

  auto max_pair = max_element(entries.begin(), entries.end(),
    [](const auto& a, const auto& b) {
      return a.second < b.second;
    }
  );

  if (max_pair != entries.end()) {
    for (auto entry : entries) {
      if (entry.second == max_pair->second) {
        result.push_back(entry.first);
      }
    } 
  }

  return result;
}

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
  int n;
  cin >> n;
  vector<entry> entries(n);

  for (int i = 0; i < n; ++i) {
    int day; string name; int amount;
    cin >> day >> name >> amount;
    entry input;
    input.day = day;
    input.name = name;
    input.amount = amount;
    entries[i] = input;
  }


  sort(entries.begin(), entries.end(), compare_days);
  
  unordered_map<string, int> tracker; 
  vector<int> visited_days;
  int days_changed = 0;
  int last_day = entries.back().day;

  for (auto entry: entries) {
      if (tracker.find(entry.name) == tracker.end()) {
        tracker[entry.name] = 0;
      } 
  }

  for (int d = 1; d <= last_day; ++d) {
    // Find the elements in first place. We will use this to determine if we need to update.
    auto initial_top_cows = top_cows(tracker);



    // Update the tracker according to today's actions.
    for (auto entry : entries) {
      if (entry.day == d) {
        tracker[entry.name] += entry.amount;
      }
    }


    auto final_top_cows = top_cows(tracker);



    if (initial_top_cows != final_top_cows) {
      ++days_changed;
    }
    
  }

  cout << days_changed << endl;

}
