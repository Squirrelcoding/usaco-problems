#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> nums;

int main() {
	freopen("speeding.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("speeding.out", "w", stdout);
  int n; int m;
  cin >> n >> m;

  vector<nums> n_lengths(n);
  vector<nums> m_lengths(m);

  for (int i = 0; i < n; ++i) {
    int length;
    int speed_limit;
    cin >> length >> speed_limit;
    n_lengths[i] = make_pair(length, speed_limit);
  } 

  for (int i = 0; i < m; ++i) {
    int length;
    int speed;
    cin >> length >> speed;
    m_lengths[i] = make_pair(length, speed);
  } 


  int current_m = 0;
  int current_n = 0;

  // The points at which an interval changes.
  int m_limit = m_lengths[0].first;
  int n_limit = n_lengths[0].first;

  int max_difference = max(0, m_lengths[0].second - n_lengths[0].second);
  // Go through each possible moment in space, get the M and N speeds, and compare them.
  for (int s = 1; s <= 100; ++s) {
    // Find the current M- and N-intervals and update them as necessary.
    if (s > m_limit) {
      current_m += 1;
      m_limit += m_lengths[current_m].first;
    }
    if (s > n_limit) {
      current_n += 1;
      n_limit += n_lengths[current_n].first;
    }

    // The new maximum could be the difference between m (the actual speed) and n (the speed limit).
    max_difference = max(max_difference, m_lengths[current_m].second - n_lengths[current_n].second);
  }

  cout << max_difference << endl;

  return 0;
}
