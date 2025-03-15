#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

void find_winners(
    vector<char>& section, 
    set<char>& individual_winners, 
    set<pair<char, char>>& team_winners
) {
  // Convert to a set
  set<char> new_set(all(section));

  // Individual winner;
  if (new_set.size() == 1) {
    individual_winners.insert(*new_set.begin());
    return;
  }
  if (new_set.size() == 2) {
    char a = *new_set.begin();
    char b = *(++new_set.begin());
    team_winners.insert(min(
      make_pair(a, b),
      make_pair(b, a)
    ));
  }
}

int main() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);
  vector<vector<char>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  cin >> grid[0][0];
  cin >> grid[0][1];
  cin >> grid[0][2];
  cin >> grid[1][0];
  cin >> grid[1][1];
  cin >> grid[1][2];
  cin >> grid[2][0];
  cin >> grid[2][1];
  cin >> grid[2][2];

  // Instead of counting them, create two sets
  // for individual winners and another set
  // for team winners.

  set<char> individual_winners;
  set<pair<char, char>> team_winners;

  // Loop through rows
  for (int i = 0; i < 3; ++i) {
    find_winners(grid[i], individual_winners, team_winners);
  }

  for (int i = 0; i < 3; ++i) {
    vector<char> column = {grid[0][i], grid[1][i], grid[2][i]};
    find_winners(column, individual_winners, team_winners);
  }


  vector<char> diagonal1 = {grid[0][0], grid[1][1], grid[2][2]};
  vector<char> diagonal2 = {grid[2][0], grid[1][1], grid[0][2]};
  find_winners(diagonal1, individual_winners, team_winners);
  find_winners(diagonal2, individual_winners, team_winners);

  cout << individual_winners.size() << endl;
  cout << team_winners.size() << endl;

  return 0;
}
