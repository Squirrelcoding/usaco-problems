#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int nxt() {
  int x;
  cin >> x;
  return x;
}

int solve(vector<vector<int>>& cards, int n, int m) {

  int s = 0;
  for (int card1 = 0; card1 < n; ++card1) {
    for (int card2 = card1; card2 < n; ++card2) {
      for (int i = 0; i < m; ++i) {
        s += abs(cards[card1][i] - cards[card2][i]);
      }
    }
  }

  return s;
}

vector<vector<int>> get_cards() {
  int n = nxt();
  int m = nxt();
  vector<vector<int>> cards(n);

  for (int i = 0; i < n; i++) {
    vector<int> vec(m);
    for (int j = 0; j < m; j++) {
      vec[j] = nxt();
    }
    cards[i] = vec;
  }
  return cards;
}


int main() {
  int t = nxt();

  vector<vector<vector<int>>> cases(t);

  vector<int> results(t);

  for (int i = 0; i < t; ++i) {
    cases[i] = get_cards();
  }

  for (auto x : cases) {
    cout << solve(x, x.size(), x[0].size()) << endl;
  }

  return 0;
}
