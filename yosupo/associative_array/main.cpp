#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int x; cin >> x; return x;
}

int main() {
  freopen("input", "r", stdin);
  int n = nxt();
  unordered_map<long long, long long> memory;
  vector<vector<long long>> instructions;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');


  string line;

  while (getline(cin, line)) {
    istringstream iss(line);
    vector<long long> nums;
    long long num;

    while (iss >> num) {
      nums.push_back(num);
    }

    instructions.push_back(nums);
  }

  for (auto& nums: instructions) {

    if (nums[0] == 1) {
      if (memory.count(nums[1])) {
        cout << memory[nums[1]] << endl;
      } else {
        cout << "0" << endl;
      }
    } else {
      memory[nums[1]] = nums[2];
    }

  }

  return 0;
}
