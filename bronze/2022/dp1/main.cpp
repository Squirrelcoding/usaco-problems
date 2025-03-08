#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;

ll nxt() {
  ll x; cin >> x; return x;
}

int main() {
  ll n = nxt();
  vector<ll> nums(n);
  generate(all(nums), nxt);
  sort(all(nums));

  // Problem: duplicates

  ll total = LONG_LONG_MIN;
  ll tuition = 0;

  // 1-index for readability
  for (int i = 0; i < n; ++i) {
    // Find the number of cows to the right
    ll num_cows = n - i;
    ll res = nums[i] * num_cows;

    if (res > total) {
      total = res;
      tuition = nums[i];
    }

    // Keep incrementing until we reach the next distinct tuition payment
    while (i+1 < n && nums[i] == nums[i+1]) {
      ++i;
    }
  }

  cout << total << " " << tuition << endl;

  return 0;
}
