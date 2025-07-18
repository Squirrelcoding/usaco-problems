#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

bool in_safe_zone(int k, int x, int n) {
  return k <= n && n <= k + x - 1;
}

// Calculates the distance travelled in decelerating from `current_speed` to `x`.
int immediate_descent(int x, int current_speed) {
  return (current_speed) * (current_speed + 1) / 2 - (x) * (x + 1) / 2;
}

// Simulates the rest of the race if we were to stop increasing at start_pos 
int plateau(int k, int x, int start_pos, int current_speed, int start_time) {
  int position = start_pos;
  int speed = current_speed;
  int time = start_time;

  while (position <= k + x - 1) {
    // If we cannot add speed to position we must decrease ASAP
    if (position + speed + immediate_descent(x, speed) > k + x - 1) {
      time += (current_speed - x);
      break; 
    }

    // Keep adding current_speed
    position += speed;
    time += 1;
  }

  return time;
}

int solve(int k, int x) {
  int min_time = k + x - 1;
  int position = 1;
  int speed = 1;
  int t = 1;

  while (t <= k + x - 1) {
    // Simulate a plateau if we were to start right now
    int res = plateau(k, x, position, speed, t);
    // If the plateau results in overshooting, break
    // Update the minimum
    min_time = min(min_time, res);
    // Increase the position 
    position += speed;
    speed += 1;
    t += 1;
  }

  return min_time;
}

int main() {
  freopen("race.in", "r", stdin);
  int k = nxt();
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);
  for (int num : nums) {
    cout << solve(k, num) << endl;
  }
}
