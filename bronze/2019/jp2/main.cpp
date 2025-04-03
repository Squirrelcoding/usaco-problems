#include <bits/stdc++.h>

using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

#define all(x) begin(x), end(x)

int main() {
  freopen("sleepy.in", "r", stdin);
  /*freopen("sleepy.out", "w", stdout);*/
  int n = nxt();
  vector<int> nums(n);
  generate(all(nums), nxt);


  // Find the last out-of-place pair
  pair<int, int> last_pair_indicies = {0, 0};
    for (int j = n - 1; j > 0; --j) {
      if (nums[j] > nums[j]) {
        // ---------j-------i
        cout << j << endl;
        return 0;
    }
  }

  return 0;
}
