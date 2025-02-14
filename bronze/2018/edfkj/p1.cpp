#include<bits/stdc++.h>

using namespace std;

int main() {
  int a;
  int b;
  int x;
  int y;
  cin >> a >> b >> x >> y;

  // The goal is to get from a to b using x and y as a shortcut.
  
  int l = min( abs(a - x) + abs(b - y), abs(a - b));
  l = min(l, abs(a - y) + abs(b - x));
  cout << l << endl;
}
