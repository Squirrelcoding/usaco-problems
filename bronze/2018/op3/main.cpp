#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
  int n = 0; cin >> n; return n;
}

vector<int> get_children(vector<vector<int>>& graph, int mother) {
  vector<int> result;
  for (int row = 0; row < graph.size(); ++row) {
    if (graph[row][mother] == 1) {
      result.push_back(row);
    }
  }
  return result;
}

pair<int, int> mother_or_aunt(vector<vector<int>>& graph, int start, int target) {
  int current = start;
  int levels = 0;

  // Loop while there is still a mother
  while(true) {
    // Look for mother index. If not found, break.
    int mother_idx = -1;
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[current][i] == 1) mother_idx = i;
    }
    if (mother_idx == -1) break;
    if (mother_idx == target) return {levels, 0};

    // LOOK FOR SIBLINGS
    vector<int> siblings = get_children(graph, mother_idx);
    for (int idx : siblings) {
      if (idx == target) return {0, 3};
    }

    // Look for grandma. Otherwise, continue.
    int gmother_idx = -1;
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[mother_idx][i] == 1) gmother_idx = i;
    }
    if (gmother_idx != -1) {

      vector<int> aunts = get_children(graph, gmother_idx);

      // See gmother's children for aunt or something
      for (int idx : aunts) {
        if (idx == target) return {levels, 1};
      }

    }
    levels++;
    current = mother_idx;
  }

  // Nothing found
  return {-1, -1};
}

set<int> get_ancestors(vector<vector<int>>& graph, int start) {
  set<int> results;
  int current = 0;
  while(true) {
    bool found_new = false;
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[start][i] == 1) {
        results.insert(i);
        current = i;
        found_new = true;
        break;
      }
    }
    if (!found_new) break;
  }
  return results;
}

int main() {
  freopen("family.in", "r", stdin);
  freopen("family.out", "w", stdout);

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
      names_to_indices.insert({mother, id});
      id++;
    }

    string child; cin >> child; 
    int child_id = id;
    if (names_to_indices.count(child)) {
      child_id = names_to_indices[child];
    } else {
      names_to_indices.insert({child, id});
      id++;
    }
    edges.push_back({child_id, mother_id});
  }


  vector<vector<int>> graph;
  for (int i = 0; i < 2 * n; ++i) {
    vector<int> v;
    for (int j = 0; j < 2*n; ++j) {
      v.push_back(0); 
    }
    graph.push_back(v);
  }

  for (auto p : edges) {
    graph[p.first][p.second] = 1;
  }


  // First see if they share a direct ancestor
  auto res1 = mother_or_aunt(graph, 0, 1);
  pair<int, int> nott = make_pair(-1, -1);
  if (res1 != nott) {
    // cow2 is res1's (great-...)mother
    if (res1.second == 0) {
      cout << cow2 << " is the ";
      for (int i = 0; i < res1.first; ++i) cout << "great-";
      cout << "mother of " << cow1 << endl;
      return 0;
    }
    // cow2 is res1's (great-...)aunt
    if (res1.second == 1) {
      cout << cow2 << " is the ";
      for (int i = 0; i < res1.first; ++i) cout << "great-";
      cout << "aunt of " << cow1 << endl;
      return 0;
    }
    if (res1.second == 3) {
      cout << "SIBLINGS" << endl;
    }
  }

  // TRY THE OTHER WAY

  auto res2 = mother_or_aunt(graph, 1, 0);
  if (res2 != nott) {
    // cow1 is cow2's (great-...)mother
    if (res2.second == 0) {
      cout << cow1 << " is the ";
      for (int i = 0; i < res2.first; ++i) cout << "great-";
      cout << "mother of " << cow2 << endl;
      return 0;
    }
    // cow1 is cow2's (great-...)aunt
    if (res2.second == 1) {
      cout << cow1 << " is the ";
      for (int i = 0; i < res2.first; ++i) cout << "great-";
      cout << "aunt of " << cow2 << endl;
      return 0;
    }

    if (res2.second == 3) {
      cout << "SIBLINGS" << endl;
      return 0;
    }
  }

  // See if they are cousins
  set<int> cow1_ancestors = get_ancestors(graph, 0);
  set<int> cow2_ancestors = get_ancestors(graph, 1);
  set<int> intersection;
  set_intersection(all(cow1_ancestors), all(cow2_ancestors), inserter(intersection, intersection.begin()));
  if (intersection.size() > 0) {
    cout << "COUSINS" << endl;
    return 0;
  }

  cout << "NOT RELATED" << endl;
  return 0;
}
