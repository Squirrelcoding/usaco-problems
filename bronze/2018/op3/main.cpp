#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n = 0; cin >> n; return n;
}

vector<int> get_children(vector<vector<int>>& graph, int mother) {
  vector<int> result;

  for (int row = 0; row < graph.size(); ++row) {
  for (int row = 0; row < graph.size(); ++row) {
  
  }

  return result;
}

pair<int, int> mother_or_aunt(vector<vector<int>>& graph, int start, int target) {


  return {0, 0};
}

int main() {
  freopen("family.in", "r", stdin);

  int n = nxt();
  string cow1; cin >> cow1;
  string cow2; cin >> cow2;

  map<string, int> names_to_indices;
  names_to_indices.insert({cow1, 0});
  names_to_indices.insert({cow2, 1});

  vector<pair<int, int>> edges;
  int id = 2;
  for (int i = 0; i < n; ++i) {
    string mother; cin >> mother; 
    int mother_id = id;
    if (names_to_indices.count(mother)) {
      mother_id = names_to_indices[mother];
    } else {
      id++;
      names_to_indices.insert({mother, mother_id});
    }

    string child; cin >> child; 
    int child_id = id;
    if (names_to_indices.count(child)) {
      child_id = names_to_indices[child];
    } else {
      id++;
      names_to_indices.insert({mother, id});
    }
    edges.push_back({mother_id, child_id});
  }

  vector<vector<int>> graph;
  for (int i = 0; i < n; ++i) {
    vector<int> v;
    for (int j = 0; j < n; ++j) {
      v.push_back(0); 
    }
    graph.push_back(v);
  }

  for (auto p : edges) {
    graph[p.first][p.second] = 1;
  }

  return 0;
}
