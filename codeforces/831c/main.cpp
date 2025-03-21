#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

set<int> possible_solutions;
vector<int> constants;

int nxt() {
  int n; cin >> n; return n;
}

void solve(set<int>& bs, int current, int i) {
  if (i == 0) {
    for (auto it = bs.begin(); it != bs.end(); ++it) {
      bs.erase(*it);
      solve(bs, *it + constants[0], i + 1);
      bs.insert(*it);
    }
    solve(bs, current, i + 1);
  }

  if (i == constants.size()) {
    possible_solutions.insert(current);
    return;
  }

  int next_c = constants[i];
  
  // Try to make all the b_i fit.
  bool done = false;
  for (auto it = bs.begin(); it != bs.end(); ++it) {
    if (*it + next_c == current) {
      done = true;
      bs.erase(*it);
      solve(bs, current, i + 1);
      bs.insert(*it);
    }
  }

  // try nothing
  solve(bs, current, i+1);
}

int main() {
  freopen("input", "r", stdin);
  int n; int k; cin >> k; cin >> n;

  vector<int> marks(k);
  generate(all(marks), nxt);

  vector<int> bs(n);
  generate(all(bs), nxt);

  /*for (auto k : marks) cout << k << " ";*/
  reverse(all(bs));

  set<int> possible_solutions;

  for (int i = 0; i < k; ++i) {
    // Find all x's that satisfy
    // x + a1 + ... + a(i) = b
      
  }
  
  cout << possible_solutions.size() << endl;

  return 0;
}
