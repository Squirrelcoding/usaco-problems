#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("evolution.in", "r", stdin);
  freopen("evolution.out", "w", stdout);

  int n = nxt();


  map<string, set<int>> m;
  for (int i = 0; i < n; ++i) {
    int k = nxt();
    for (int j = 0; j < k; ++j) {
      string s;
      cin >> s;
      m[s].insert(i);
    }
  }
  /**/
  /*for (auto p : m) {*/
  /*  cout << p.first << ": ";*/
  /*  for (auto s : p.second) {*/
  /*    cout << s << " ";*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/
  /**/
  for (auto p : m) {
    for (auto q : m) {
      if (p.first == q.first) continue;
      // Get the cows that have feature p
      set<int> p_cows = p.second;

      // Get the cows that have feature q
      set<int> q_cows = q.second;

      // Intersection
      set<int> pq_cows;
      set_intersection(all(p_cows), all(q_cows), inserter(pq_cows, pq_cows.begin()));
      if (
          p_cows.size() - pq_cows.size() > 0 && 
          q_cows.size() - pq_cows.size() > 0 &&
          pq_cows.size() > 0
          ) {
        cout << "no" << endl;
        return 0;
      }
    }
  }

  cout << "yes" << endl;
  return 0;
}
