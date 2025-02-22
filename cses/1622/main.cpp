#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


set<string> permutations;
unordered_map<char, int> chars;
string str;

// Generates a string using the characters from 0 to index and adds them to permutations
void generate_permutatons(string& current_string) {

  bool is_empty = true;
  // check if all chars are zero so we can return
  for (auto pair : chars) {
    if (pair.second != 0) {
      is_empty = false; 
    }
  }

  if (is_empty) {
    permutations.insert(current_string);
    return;
  }

  for (auto pair : chars) {
    if (pair.second == 0) {
      continue;
    }
    chars[pair.first] -= 1;
    current_string.push_back(pair.first);
    generate_permutatons(current_string);
    chars[pair.first] += 1;
    current_string.pop_back();
  }

}

int main() {
  string s;
  cin >> s;


  for (char c : s) {
    chars[c]++;
  }
  generate_permutatons(str);

  cout << permutations.size() << endl;
  for (auto perm : permutations) {
    cout << perm << endl;
  }


  return 0;
}
