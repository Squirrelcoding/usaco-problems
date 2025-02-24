#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> cow;
typedef tuple<int, int, int, int> cooler;

int stalls[100] = {0};

int calculate_cost(vector<cow>& cows, vector<cooler>& coolers) {
  int cost = 0;

  // Populate the stalls
  for (auto cooler : coolers) {
    for (int i = get<0>(cooler); i <= get<1>(cooler); ++i) {
      stalls[i] += get<2>(cooler);
    }
    cost += get<3>(cooler);
  }

  // Check if each cow is satisfied
  for (auto cow : cows) {
    for (int i = get<0>(cow); i <= get<1>(cow); ++i) {
      if (stalls[i] < get<2>(cow)) {
        // Reset stalls
        fill(stalls, stalls + 100, 0);
        return INT_MAX;
      }
    }
  }

  // Reset stalls
  fill(stalls, stalls + 100, 0);
  return cost;
}

int main() {
  /*freopen("in", "r", stdin);*/
  int n; int m;

  cin >> n >> m;

  vector<cow> cows(n);
  vector<cooler> coolers(m);

  for (int i = 0; i < n; ++i) {
    int a; int b; int c;
    cin >> a >> b >> c;
    cows[i] = make_tuple(a, b, c);
  }

  for (int i = 0; i < m; ++i) {
    int a; int b; int c; int d;
    cin >> a >> b >> c >> d;
    coolers[i] = make_tuple(a, b, c, d);
  }

  int min_cost = INT_MAX;

  for (int b = 0; b < (1<<m); b++) {
    vector<cooler> subcoolers;
    for (int i = 0; i < m; i++) {
      if (b&(1<<i)) subcoolers.push_back(coolers[i]);
    }

    min_cost = min(min_cost, calculate_cost(cows, subcoolers));
  }

  cout << min_cost << endl;

  return 0;
}
