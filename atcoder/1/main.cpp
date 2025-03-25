#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("input", "return", stdin);

  int n = nxt();

  vector<int> as(n);
  generate(all(as), nxt);
  vector<int> bs(n);
  generate(all(bs), nxt);
  vector<int> cs(n);
  generate(all(cs), nxt);

  /*for (int i = 0; i < n; ++i) cp[i] = ;*/

  map<int, int> a_frequency;
  for (int a : as) a_frequency[a]++;

  unordered_map<int, int> b_frequency;
  for (int i = 0; i < n; ++i) {
    if (bs[cs[i]] != 0) b_frequency[bs[cs[i]]]++;
  }

  int total_pairs = 0;

  for (auto it = a_frequency.begin(); it != a_frequency.end(); ++it) {
    if (b_frequency.count(it->first)) {
      total_pairs += b_frequency[it->first] * it->second;
    }
  }

  cout << total_pairs << endl;


  return 0;
}
