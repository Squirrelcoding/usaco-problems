#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);

  int x1 = nxt();
  int y1 = nxt();
  int x2 = nxt();
  int y2 = nxt();

  int x3 = nxt();
  int y3 = nxt();
  int x4 = nxt();
  int y4 = nxt();

  int bottom_left_x = min(x1, x3);
  int bottom_left_y = min(y1, y3);

  int top_right_x = max(x2, x4);
  int top_right_y = max(y2, y4);

  int y_choice = max(y2, y4) - min(y1, y3);
  int x_choice = max(x2, x4) - min(x1, x3);
  
  cout << max(y_choice * y_choice, x_choice * x_choice) << endl;

  return 0;
}
