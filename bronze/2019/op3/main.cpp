#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

int nxt() {
  int n; cin >> n; return n;
}

// Attempts to split the subpopulations. REMEMBER EMPTY ONES
bool form_split(vector<set<int>> subpopulations, int max_features) {
  
  // Feature `i` is the splitter.
  for (int i = 0; i < max_features; ++i) {
    set<int> without = {};
    set<int> with = {};
  
    for (auto subpop : subpopulations) {
      if (subpop.count(i)) {
        with.insert(all(subpop)); 
      } else {
        without.insert(all(subpop)); 
      }
    }

    set<int> intersect;
    set_intersection(all(without), all(with), inserter(intersect, intersect.begin()));
    if (intersect.size() != 0) {
      return false;
    }
  } 

  return true;
}

int main() {
  freopen("evolution.in", "r", stdin);
  int n = nxt();
  vector<set<int>> subpopulations;
  map<string ,int> features;

  int id = 0;

  for (int i = 0; i < n; ++i) {
    int k = nxt();
    set<int> subpop = {};
    for (int j = 0; j < k; ++j) {
      string s;
      cin >> s;
      if (features.count(s)) {
        subpop.insert(features[s]);
      } else {
        features.insert({s, id});
        subpop.insert(features[s]);
        id++;
      }
    }
    subpopulations.push_back(subpop);
  }

  if (form_split(subpopulations, id)) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}
