#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int main() {
  freopen("tttt.in", "r", stdin);
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


  int individual_winners = 0;
  int team_winners = 0;

  set<char> existing_winners;

  // Loop through rows
  for (int i = 0; i < 3; ++i) {
    set<char> s;
    s.insert(all(grid[i]));
    if (s.size() == 1) individual_winners++;
    if (s.size() == 2) team_winners++;
  }


  // Loop through columns
  for (int i = 0; i < 3; ++i) {
    set<char> s;
    for (int j = 0; j < 3; ++j) s.insert(grid[j][i]);
    s.insert(all(grid[i]));
    if (s.size() == 1) individual_winners++;
    if (s.size() == 2) team_winners++;
  }

  // Check up-left to bottom-right diagonal
  set<char> diagonal1 = {grid[0][0], grid[1][1], grid[2][2]};
  if (diagonal1.size() == 1) individual_winners++;
  if (diagonal1.size() == 2) team_winners++;
  set<char> diagonal2 = {grid[2][0], grid[1][1], grid[0][2]};
  if (diagonal2.size() == 1) individual_winners++;
  if (diagonal2.size() == 2) team_winners++;

  cout << individual_winners << endl;
  cout << team_winners << endl;

  return 0;
}
