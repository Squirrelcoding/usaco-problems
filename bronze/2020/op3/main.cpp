#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> interaction;

int main() {
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  int n; int interactions_count;
  cin >> n >> interactions_count;

  string final_results;
  cin >> final_results;

  vector<int> infected_cows;
  unordered_set<int> patient_zero_candidates;

  for (int i = 0; i < final_results.size(); ++i) {
    // Find the total number of cows that are infected.
    if (final_results[i] == '1') {
      infected_cows.push_back(i);
      patient_zero_candidates.insert(i);
    }
  }

  vector<interaction> interactions(interactions_count);

  for (int i = 0; i < interactions_count; ++i) {
    int t; int x; int y;
    cin >> t >> x >> y;
    interactions.push_back(make_tuple(t, x, y));
  }


  // Find out which cows are NOT patient zero. This only happens if the cow ends up being infected in the end
  for (auto interaction : interactions) {
    // Check if the first one is healthy and the second one is final infected.
    if (find(infected_cows.begin(), infected_cows.end(), get<1>(interaction)) == infected_cows.end()) {
      if (find(infected_cows.begin(), infected_cows.end(), get<2>(interaction)) != infected_cows.end()) {
        patient_zero_candidates.erase(get<2>(interaction));
      }
    }
    if (find(infected_cows.begin(), infected_cows.end(), get<2>(interaction)) == infected_cows.end()) {
      if (find(infected_cows.begin(), infected_cows.end(), get<1>(interaction)) != infected_cows.end()) {
        patient_zero_candidates.erase(get<1>(interaction));
      }
    }
  }
  // just a lil comment
  return 0;
}
