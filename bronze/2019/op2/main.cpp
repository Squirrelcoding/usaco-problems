#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

int main() {
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);

  int n = nxt();

  // Form an adjacency matrix 
  int graph[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      graph[i][j] = 0;
    }
  } 
  for (int i = 0; i < n - 1; ++i) {
    int a = nxt() - 1;
    int b = nxt() - 1;
    graph[a][b] = 1;
    graph[i][i] = 1;
  }
  graph[n - 1][n - 1] = 1;



  // supergraph[i][j] = true iff there is a path from i to j, including any intermediate nodes
  for (int row = 0; row < n; ++row) {
    // Loop through the rows neighbors
    for (int neighbor = 0; neighbor < n; ++neighbor) {
      if (graph[row][neighbor] == 1) {
        for (int i = 0; i < n; ++i) {
          graph[row][i] = max(graph[row][i], graph[neighbor][i]);
        }
      }
    }
  }

  // do it backwards
  for (int row = n - 1; row >= 0; --row) {
    // Loop through the rows neighbors
    for (int neighbor = n - 1; neighbor >= 0; --neighbor) {
      if (graph[row][neighbor] == 1) {
        for (int i = 0; i < n; ++i) {
          graph[row][i] = max(graph[row][i], graph[neighbor][i]);
        }
      }
    }
  }

  for (int col = 0; col < n; ++col) {
    int size = 0;
    for (int row = 0; row < n; ++row) {
      if (graph[row][col] == 1) size++; 
    }
    if (size == n) {
      cout << col + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
