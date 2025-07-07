#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("swap.in", "r", stdin);
  int n = nxt();
  int k = nxt();
  int a1 = nxt();
  int a2 = nxt();
  int b1 = nxt();
  int b2 = nxt();

  vector<int> map;
  for (int i = 0; i <= n; ++i) {map.push_back(i);}


  cout << a1 << " " << a2 << endl;
  // First apply the A swaps
  for (int i = a1; i <= a2; ++i) {
    map[i] = a2 - (map[i] % (a2 - a1));
  }

  // Apply the Bs
  /*for (int i = b1; i <= b2; ++i) {*/
  /*  map[i] = b2 - (map[i] % (b2 - b1));*/
  /*}*/

  for (int i = 0; i < n; ++i) {
    cout << map[i] << endl;
  }

  return 0; 
}
