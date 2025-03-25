#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("input", "r", stdin);

  int n;
  cin >> n;

  vector<int> a(n+1);
  vector<int> b(n+1);
  vector<int> c(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];    
  for (int i = 1; i <= n; ++i) cin >> c[i];

  // Count the numbers of the b-c-array and put them into a frequency counter
  // The problem is most likely here
  unordered_map<int, int> b_freq;
  for (int i = 1; i <= n; ++i) {
    int val = b[c[i]];
    b_freq[val]++;
  }

  // Count the numbers of a and put them into a frequency counter
  unordered_map<int, int> a_freq;
  for (int i = 1; i <= n; ++i) {
    a_freq[a[i]]++;
  }

  long long total = 0;

  for (int i = 1; i <= n; ++i) {
    total += (long long) a_freq[i] * b_freq[i];
  }

  cout << total << endl;

  return 0;
}
