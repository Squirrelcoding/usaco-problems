#include <bits/stdc++.h>

using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);
  int a = nxt();
  int b = nxt();
  int c = nxt();

  int x = b - a;
  int y = c - b;

  if (x == 1 && y == 1) {
    cout << 0 << endl;
    cout << 0 << endl;
    return 0;
  }

  // Calculate minimum value
  if (x == 2 || y == 2) {
    cout << 1 << endl;
  } else if (x >= 3 || y >= 3) {
    cout << 2 << endl;
  }
  
  int max_difference = max(x, y);

  cout << max_difference - 1 << endl;

  return 0;
}
