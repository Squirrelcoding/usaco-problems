#include <bits/stdc++.h>

using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  int a = nxt();
  int b = nxt();
  int c = nxt();

  int x = b - a;
  int y = c - b;

  int steps = 0;
  while (x > 1 || y > 1) {
    // Case I: x == 1
    if (x == 1) {
      x = 1;
      y = y-1;
    } else if (y == 1) {
      y = x-1;
      x = 1;
    } else {
      int smaller = min(x, y);
      if (smaller == x) {
        x = 1;
        y = smaller - 1;
      } else {
        x = smaller - 1;
        y = 1;
      }
    }
    steps++;
  }
  
  cout << steps << endl;

  return 0;
}
