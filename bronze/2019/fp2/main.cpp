#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

void color_node(int colorings[], vector<int> adj[], int i) {
}

int main() {
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
  int n = nxt();
  int m = nxt();

  vector<pair<int, int>> edge_pairs;
  for (int i = 0; i < m; ++i) {
    int a = nxt();
    int b = nxt();
    edge_pairs.push_back({a - 1, b - 1});
  }

  // Create an adjacency list
  vector<int> adj[n];

  for (int i = 0; i < m; ++i) {
    pair<int, int> p = edge_pairs[i];
    adj[p.first].push_back(p.second); 
    adj[p.second].push_back(p.first); 
  }

  int colorings[n];
  fill(colorings, colorings + n, 0);
  
  for (int i = 0; i < n; ++i) {

  set<int> choices = {4, 3, 2, 1}; 
  for (int neighbor : adj[i]) {
    choices.erase(colorings[neighbor]);
  }

  set<int>::iterator iter1 = choices.begin();
  int choice = *iter1;

  colorings[i] = choice;
  }

  for (int n : colorings) {
    cout << n;
  }
  cout << endl;

  return 0;
}
