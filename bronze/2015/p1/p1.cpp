// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	int c, d;
  cin >> a >> b;
  cin >> c >> d;

  // Case I: a < c <= b < d
  if (a < c && c <= b && b < d) {
    cout << (d-c) + (b-a) + (b-c) << endl;
  }
  // Case II: a < b <= c < d
  if (b <= c) {
    cout << (b-a) + (c-d) << endl;
  }

  // Case  III: a < c < d < b
  if (a <= c && d <= b) {
    cout << b - a << endl;
  }

  // Case IV: c < a <= d < b
  if (c < a && a <= d && d < b) {
    cout << (d-c) + (b-a) + (d-a) << endl;
  }
  // Case II: a < b <= c < d
  if (b <= c) {
    cout << (b-a) + (c-d) << endl;
  }


}

