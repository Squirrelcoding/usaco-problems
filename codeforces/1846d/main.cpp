#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

double nxt() {
  double n; cin >> n; return n;
}

int main() {
  /*freopen("input", "r", stdin);*/
  int t = nxt();
  cout << fixed << setprecision(10);
  for (int l = 0; l < t; ++l) {
    int n = nxt();
    double d =  nxt();
    double h = nxt();

    double total_area = (d * h * 0.5) * n;
    vector<double> y(n);
    generate(all(y), nxt);

    for (int i = 0; i < n - 1; ++i) {
      total_area -= 0.5 * d * pow(max(y[i] + h - y[i + 1], 0.0), 2.0) / h;
    }
    cout << total_area << endl;
  }
  return 0;
}
