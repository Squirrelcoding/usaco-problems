#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
  int n;
  cin >> n;
  return n;
}

int main() {
  // freopen("input", "r", stdin);
  int t = nxt();
  for (int _i = 0; _i < t; ++_i) {
    int n = nxt();
    vector<int> nums(n);
    generate(all(nums), nxt);

    // Form an adjacency list
    map<int, vector<int>> adjacency_list;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (i - j == nums[i] - nums[j]) {
          if (adjacency_list.count(i)) {
            adjacency_list[i].push_back(j);
          } else {
            adjacency_list[i] = {j};
          }
        }
      }
    }

    set<int> visited_nodes;

    int result = 0;
    for (auto p : adjacency_list) {
      if (visited_nodes.count(p.first))
        continue;
      for (int i : p.second) {
        visited_nodes.insert(i);
      }
      vector<int> numbers;
      for (int i : p.second)
        numbers.push_back(nums[i]);
      // sort(all(numbers));

      int total = 0;

      for (int i = numbers.size() - 1; i >= 1; i -= 2) {
        int current_sum = numbers[i] + numbers[i - 1];
        if (current_sum < 0) {
          break;
        }
        total += current_sum;
      }
      result += total;
    }
    cout << result << endl;
  }
  return 0;
}
