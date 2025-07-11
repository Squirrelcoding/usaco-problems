#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int nxt() {
  int n; cin >> n; return n;
}

class Node {
public:
    int data;
    Node* left, * right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
  freopen("evolution.in", "r", stdin);

  int n = nxt();

  vector<vector<int>> strings;

  int id = 0;
  map<string, int> m;
  for (int i = 0; i < n; ++i) {
    int k = nxt();
    vector<int> v(k);
    for (int j = 0; j < n; ++j) {
      string s;
      cin >> s;
      if (m.count(s)) {
        m[s] = id;
        id++;
      }
      v.push_back(m[s]);
    }
  }

  for (auto v : strings) {
    sort(all(v));
  }
  
  Node* start = new Node(-1);
  


  return 0;
}
