#include <bits/stdc++.h>

using namespace std;


int main() {
  freopen("blocks.in", "r", stdin); 
  freopen("blocks.out", "w", stdout); 

  int n;
  cin >> n;

  vector<pair<string, string>> boards(n);

  for (int i = 0; i < n; i++) {
    string a; string b;
    cin >> a >> b;
    boards[i] = make_pair(a, b);
  }
  
  // Initiate and populate the frequencies;
  unordered_map<char, int> frequencies;

  for (int i = 65; i <= 90; i++) {
    frequencies[char(i)] = 0;
  }

  for (auto board : boards) {
    // Count the number of unique instances of each letter in each word. 
    unordered_map<char, int> first;
    unordered_map<char, int> second;
    for (char i = 'a'; i <= 'z'; ++i) {
      first[i] = 0;
    }

    for (char i = 'a'; i <= 'z'; ++i) {
      second[i] = 0;
    }

    for (char c : board.first) {
      first[c] += 1;
    }

    for (char c : board.second) {
      second[c] += 1;
    }

    for (char i = 'a'; i <= 'z'; ++i) {
      frequencies[i] += max(first[i], second[i]);
    }
  }

    for (char i = 'a'; i <= 'z'; ++i) {
      cout << frequencies[char(i)] << endl;
    }

  
  return 0;
}
