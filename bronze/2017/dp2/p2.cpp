#include <bits/stdc++.h>

using namespace std;

/* Modifies a vector in-place such that if v[i] = j, 
 * then v[j] = i in the new vector. 
 * @param v The vector in question.
 * The pattern vector describes the movements. The item at position pattern[i] gets moved to i.
*/
void shift(vector<int>& v, vector<int>& pattern) {
  // Create an array with the original positions of the IDs.
  vector<int> v_copy(v.size()); 

  for (int i = 0; i < v.size(); ++i) {
    v_copy[i] = v[i];
  }

  for (int i = 0; i < v.size(); ++i) {
    v[i] = v_copy[pattern[i]];
  }
}

int main() {
  freopen("shuffle.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("shuffle.out", "w", stdout);

  int n; 
  cin >> n;

  vector<int> shuffle(n);

  // Populate the shuffle vector
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    shuffle[i] = k - 1;
  }

  vector<int> ids(n);

  // Populate the ID vector.
  for (int i = 0; i < n; ++i) {
    // Populate the ID vector.
    int k;
    cin >> k;
    ids[i] = k;
  }

  // Reverse the shuffle
  shift(ids, shuffle);
  shift(ids, shuffle);
  shift(ids, shuffle);

  for (int i = 0; i < n; ++i) {
    cout << ids[i] << endl;
  }


  return 0;
}

