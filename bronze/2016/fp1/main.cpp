#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x; int y; int m;
  cin >> x >> y >> m;

  // Objective: find the values of X and Y that maximize M.
  // We should look at like the border.

  int result = INT_MIN;
  for (int i = 0; i <= m / x; ++i) {
    for (int j = 0; j <= m / y; ++j) {
      if (i*x+j*y <= m) {
        result = max(result, i*x+j*y);
      }
    }
  }

  cout << result << endl;
    
  return 0;
}
