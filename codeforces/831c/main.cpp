#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  int n; int k; 
  cin >> k; cin >> n;

  vector<int> marks(k);
  generate(all(marks), nxt);

  vector<int> bs(n);
  generate(all(bs), nxt);

  int s = 0;
  vector<int> constants(k);
  for (int i = 0; i < k; ++i) {
    s += marks[i];
    constants[i] = s;
  }

  vector<set<int>> table(n);

  for (int c : constants) {
    for (int i = 0; i < n; ++i) {
      int answer = bs[i] - c;
      table[i].insert(answer);
    }
  }

  int total_answers = 0;

  for (auto it = table[0].begin(); it != table[0].end(); ++it) {
    bool good = true;
    for (int i = 1; i < n; ++i) {
      if (!table[i].count(*it)) {
        good = false;
        break;
      }
    }
    if (good) ++total_answers;
  }

  cout << total_answers << endl;
 
  return 0;
}

