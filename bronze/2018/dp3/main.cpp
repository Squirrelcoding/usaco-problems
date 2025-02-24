#include <bits/stdc++.h>

using namespace std;

void solve(
    unordered_set<int>& solutions, 
    unordered_map<int, int>& barn1_buckets, 
    unordered_map<int, int>& barn2_buckets, 
    int day, 
    int barn1) {
  if (day == 4) {
    solutions.insert(barn1);
    return;
  }

  // If it's Wednesday, or Friday
  if (day % 2 == 0) {

  vector<pair<int, int>> keys;
  for (auto pair : barn1_buckets) {
    if (pair.second > 0) keys.push_back(pair);
  }

    // Carry bucket from barn 1 to barn 2
    for (auto pair: keys) {
      if (pair.second <= 0) continue;
      barn1_buckets[pair.first]--;
      barn2_buckets[pair.first]++;
      solve(solutions, barn1_buckets, barn2_buckets, day+1, barn1 - pair.first);
      barn2_buckets[pair.first]--;
      barn1_buckets[pair.first]++;
    }
  } else {
  vector<pair<int, int>> keys;
  for (auto pair : barn2_buckets) {
    if (pair.second > 0) keys.push_back(pair);
  }
    for (auto pair: keys) {
      if (pair.second <= 0) continue;
      barn2_buckets[pair.first]--;
      barn1_buckets[pair.first]++;
      solve(solutions, barn1_buckets, barn2_buckets, day+1, barn1 + pair.first);
      barn1_buckets[pair.first]--;
      barn2_buckets[pair.first]++;
    }
  }
}

int main() {
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);
  unordered_map<int, int> barn1_buckets;
  unordered_map<int, int> barn2_buckets;
  unordered_set<int> solutions;

  for (int i = 0; i < 10; ++i) {
    int n;
    cin >> n;
    barn1_buckets[n] += 1;
  }

  for (int i = 0; i < 10; ++i) {
    int n;
    cin >> n;
    barn2_buckets[n] += 1;
  }

  solve(solutions, barn1_buckets, barn2_buckets, 0, 1000);

  cout << solutions.size() << endl;

  return 0;
}
