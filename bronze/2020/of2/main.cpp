#include<bits/stdc++.h>
#include <cstdio>

using namespace std;

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);
  int n = nxt();
  string a; cin >> a;
  string b; cin >> b;

  int result = 0;

  for (int i = 0; i < n; ++i) {
    int counter = 0;
    while (a[i] != b[i]) {
      i += 1;
      ++counter;
    }
    if (counter > 0) ++result;
  }

  cout << result << endl;

  return 0;
}
