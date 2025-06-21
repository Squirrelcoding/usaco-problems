#include <bits/stdc++.h>

using namespace std;


#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  /*freopen("input", "r", stdin);*/
  int n = nxt();
  string input;
  cin >> input;

  vector<int> data; 

  for (int i = 0; i < n; i += 2) {
    char first_char = input[i];
    char second_char = input[i + 1];
    if (first_char == 'G' && second_char == 'H') {
      data.push_back(1);
    } else if (first_char == 'H' && second_char == 'G') {
      data.push_back(0);
    }
  }

  int step_counter = 0;
  for (int i = data.size() - 1; i >= 0; --i) {
    if ((data[i] + step_counter) % 2 == 1) ++step_counter;
  }

  cout << step_counter << endl;

  return 0;
}
