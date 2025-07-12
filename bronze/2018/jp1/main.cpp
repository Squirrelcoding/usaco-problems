#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define cp pair<int, int>

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  cp cowfeed_bl = {nxt(), nxt()};
  cp cowfeed_tr = {nxt(), nxt()};

  cp mower_bl = {nxt(), nxt()};
  cp mower_tr = {nxt(), nxt()};

  int area = abs(cowfeed_tr.second - cowfeed_bl.second) * abs(cowfeed_tr.first - cowfeed_bl.first);

  // Find the complete overlapped area
  // Case I: cowfeed_bl.X < mower_bl.X < mower_tr.X < cowfeed_tr.X
  if (cowfeed_bl.first < mower_bl.first && mower_tr.first < cowfeed_tr.first) {
    // Find the overlapped y_area, if any.
    int overlapped_y = abs(min(mower_tr.first, cowfeed_tr.first)) - abs(max(mower_bl.first, cowfeed_bl.first));
    cout << area - overlapped_y * abs(cowfeed_tr.first - cowfeed_bl.first) << endl;
    return 0;
  }

  // Case II: cowfeed_bl.Y < mower_bl.Y < mower_tr.Y < cowfeed_tr.Y
  if (cowfeed_bl.second < mower_bl.second && mower_tr.second < cowfeed_tr.second) {
    // Find the overlapped y_area, if any.
    int overlapped_x = abs(min(mower_tr.second, cowfeed_tr.second)) - abs(max(mower_bl.second, cowfeed_bl.second));
    cout << area - overlapped_x * abs(cowfeed_tr.second - cowfeed_bl.second) << endl;
    return 0;
  }

  cout << area << endl;
  return 0;
}
