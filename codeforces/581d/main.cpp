#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> box;

int main() {
  vector<int> sizes;

  int n = -1;
  int max_box = -1;
  for (int i = 0; i < 6; ++i) {
    int k;
    cin >> k;
    sizes.push_back(k);
    if (k > n) {
      n = k;
      max_box = i / 2;
    }
  }

  // Sort the boxes by having the larger coordinate always be first.
  for (int i = 0; i < 6; i += 2) {
    int a = min(sizes[i], sizes[i+1]);
    int b = max(sizes[i], sizes[i+1]);
    sizes[i] = b;
    sizes[i+1] = a;
  }

  // The other two boxes that are less than or equal to the one
  vector<pair<int, int>> boxes;
  for (int i = 0; i < 3; ++i) {
    if (i != max_box) {
      boxes.push_back(make_pair(sizes[2*i], sizes[2*i+1]));
    }
  }


  for (auto b : boxes) {
    cout << "Smaller box: " << "(" << b.first << ", " << b.second << ")" << endl;
  }

  // If stacking all three on top of each other doesn't work, try the other way.
  // Stacking will only work if all three have some coordinate that is all the same
  // So we check for that here.
  if (sizes[0] == sizes[2] && sizes[2] == sizes[4]) {
    for (int i = 0; i < sizes[1]; ++i) {
      for (int j = 0; j < n; j++) cout << "A";
      cout << endl;
    }
    for (int i = 0; i < sizes[3]; ++i) {
      for (int j = 0; j < n; j++) cout << "B";
      cout << endl;
    }
    for (int i = 0; i < sizes[5]; ++i) {
      for (int j = 0; j < n; j++) cout << "C";
      cout << endl;
    }
    return 0;
  }

  // Attempt to fit the other two smaller boxes
  if (boxes[0].first + boxes[1].first == n) {
    
  } 
  else if (boxes[0].first + boxes[1].second == n) {

  } 
  else if (boxes[0].second + boxes[1].first == n) {

  } 
  else if (boxes[0].second + boxes[1].second == n) {

  } 

  cout << "-1" << endl;  
  return 0;
}
