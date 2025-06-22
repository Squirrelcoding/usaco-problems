#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

bool in_safe_zone(int k, int x, int n) {
  return k <= n && n <= k + x - 1;
}

int solve(int k, int x) {
  int current_pos = 0;
  int current_speed = 0;
  int t = 0;
  int mode = 1;

  // While NOT in the safe zone
  while (in_safe_zone(k, x, current_pos)) {

    // Recall that "landing in the safe zone" is equivalent to having the final speed by at most x.

    // If we increase our speed by one more and then try to decrease as fast as possible,
    // and we land outside the safe zone, we will decrease the speed NOW.
    if (!in_safe_zone(k, x, current_pos + (current_speed + 1) * (current_speed + 2) / 2 - (x + 1) * (x + 2) / 2)) {
      mode = -1;
    }

    // If we don't increase our speed and we DO land in the safe zone, but not as fast
    // as possible, increase speed

    // If we're going as fast as possible while landing in the safe zone, don't change speed.
    mode = 0;
  }

  return 0;
}

int main() {
  // PLAN: The "safe zone" is the closed interval [K, K + X - 1]. Find the minimum number of steps needed to land in the safe zone.
  // The graph of the velocity should be like a bell-shape. It should have a peak and stuff
  int k = nxt();
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);
}
