#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int x; cin >> x; return x;
}

int main() {
  freopen("cowqueue.in", "r", stdin);
  freopen("cowqueue.out", "w", stdout);
  int n = nxt();

  vector<pair<int, int>> cows(n);

  for (int i = 0; i < n; ++i) {
    int time = nxt();
    int duration = nxt();
    cows[i] = {time, duration};
  }

  // Sort the pairs
  sort(all(cows));

  // Simulate
  int t = 0;
  for (auto cow : cows) {

    // If the cow's starting time is greater than all of the current time,
    // just skip forward to it
    if (cow.first > t) {
      t = cow.first;
    }
    t += cow.second;
  }
   

  cout << t << endl;

  return 0;
}
