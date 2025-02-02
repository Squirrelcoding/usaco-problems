#include <bits/stdc++.h>

using namespace std;

enum Type {
  None,
  OnRamp,
  OffRamp
};


typedef tuple<Type, int, int> seg;

seg get_result(vector<seg>& segments) {
  pair<int, int> result = {0, 1000};

  for (auto segment : segments) {
    // If we're updating 
    if (get<0>(segment) == Type::None) {
      result.first = max(result.first, get<1>(segment)); 
      result.second = min(result.second, get<2>(segment)); 
    }
    if (get<0>(segment) == Type::OnRamp) {
      result.first += get<1>(segment);
      result.second += get<2>(segment);
    }
    if (get<0>(segment) == Type::OffRamp) {
      result.first -= get<2>(segment);
      result.second -= get<1>(segment);
    }
  }

  return make_tuple(Type::None, result.first, result.second);
}


int main() {
	freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
	// the following line creates/overwrites the output file
  vector<seg> segments;
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string type; int lower; int upper;
    Type t;
    cin >> type >> lower >> upper;
    if (type == "on") {
      t = OnRamp;
    } 
    if (type == "off") {
      t = OffRamp;
    } 
    if (type == "none") {
      t = None;
    }
    segments.push_back(make_tuple(t, lower, upper));
  }

  auto end_result = get_result(segments);


  vector<seg> new_segments; 

  for (auto riter = segments.rbegin(); riter != segments.rend(); ++riter) {
    auto segment = *riter;
    if (get<0>(segment) == Type::OffRamp) {
      new_segments.push_back(make_tuple(Type::OnRamp, get<1>(segment), get<2>(segment)));
    } 
    if (get<0>(segment) == Type::OnRamp) {
      new_segments.push_back(make_tuple(Type::OffRamp, get<1>(segment), get<2>(segment)));
    } 
    if (get<0>(segment) == Type::None) {
      new_segments.push_back(segment);
    }
  }

  auto first_result = get_result(new_segments);

  cout << get<1>(first_result) << " " << get<2>(first_result) << endl;
  cout << get<1>(end_result) << " " << get<2>(end_result) << endl;


  return 0;
}
