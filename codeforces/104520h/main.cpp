#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
int nxt() {
  int x; cin >> x; return x;
}
 
int main() {
  int n = nxt();
 
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) a[i] = nxt();
  for (int i = 0; i < n; ++i) b[i] = nxt();
 
  vector<long long> x(n);
  for (int i = 0; i < n; ++i) x[i] = (long long) (i+1) * (n-i) * a[i];
 
  sort(all(x));
  sort(all(b), greater<>());
 
  long long minimized = 0;
  for (int i = 0; i < n; ++i) minimized += (long long) x[i] * b[i];
 
  cout << minimized << endl;
 
  return 0;
}
