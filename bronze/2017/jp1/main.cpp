#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  map<string, int> cows;
  cows["Bessie"] = 0;
  cows["Elsie"] = 0;
  cows["Daisy"] = 0;
  cows["Gertie"] = 0;
  cows["Annabelle"] = 0;
  cows["Maggie"] = 0;
  cows["Henrietta"] = 0;
  int n; cin >> n; 
  string cow_name;
  int amount;

  for (int i = 0; i < n; ++i) {
    cin >> cow_name; cin >> amount;
    cows[cow_name] += amount;
  }

  vector<int> values;
  for (auto x : cows) {
    values.push_back(x.second);
  }

  set<int> s(values.begin(), values.end());

  if (s.size() == 1) {
    cout << "Tie" << endl;
    return 0;
  }

  int second_minimum = *(++s.begin());

  int winner_count = 0;
  string winner;

  for (auto x : cows) {
    if (x.second == second_minimum) {
      winner_count += 1;
      winner = x.first;
    }
  }

  if (winner_count == 1) {
    cout << winner << endl;
  } else {
    cout << "Tie" << endl;
  }


  return 0;
}
