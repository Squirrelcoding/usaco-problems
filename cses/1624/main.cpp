#include <bits/stdc++.h>

using namespace std;

typedef long long num;

bool is_valid(num n) {
    unordered_set<char> digits;
    string num = to_string(n);
    
    for (char digit : num) {
        if (digits.count(digit)) return false;  // Duplicate found
        digits.insert(digit);
    }
  return true;
}

vector<pair<num, num>> solve(int n) {
  vector<pair<num, num>> result;
  for (num s2 = 1; s2 <= 9876543210 / n; ++s2) {
    num s1 = n * s2;
    if (is_valid(s1) && is_valid(s2)) {
      result.push_back(make_pair(s1, s2));
    }
  }
  return result;
}

int main() {
  int n;
  cin >> n;

  cin.ignore();

  vector<num> inputs;

  for (int i = 0; i < n; ++i) {
    num k;
    cin >> k;
    inputs.push_back(k);
  }

  for (num input : inputs) {
    auto res = solve(input);

    for (auto solution : res) {
      cout << solution.first << " / " << solution.second << " = " << input << endl;
    }

    cout << endl;
  }

  return 0;
}
