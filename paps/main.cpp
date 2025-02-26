#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input; // Read input without prompts

    unordered_map<char, int> char_count;

    int len = 0;
    for (char ch : input) {
        char_count[ch]++;
        len++;
    }
    
    vector<char> letters(len);
    
    int odd_instances = 0;
    char odd_char;
    int p = 0;
    for (const auto& pair : char_count) {
      if (odd_instances > 1) {
        cout << "NO SOLUTION" << endl; 
        return 0;
      }
      if (pair.second % 2 == 1) {
        odd_char = pair.first;
        odd_instances++;
        continue;
      }
      for (int i = 0; i < pair.second / 2; ++i) {
        letters[p] = pair.first;
        letters[len - 1 - p] = pair.first;
        p++;
      }
    }

      if (odd_instances > 1) {
        cout << "NO SOLUTION" << endl; 
        return 0;
      }

    if (odd_instances != 0) {
      p = (len + 1) / 2 - 1;
      letters[p] = odd_char;
      int i = 1;
      while (i < (char_count[odd_char] + 1) / 2) {
        letters[p - i] = odd_char; 
        letters[p + i] = odd_char; 
        i += 1;
      }
    }
    for (auto c : letters) {
      cout << c;
    }
    cout << endl;
    return 0;
}
