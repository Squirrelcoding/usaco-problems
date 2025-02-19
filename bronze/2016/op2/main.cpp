#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<int, int>> cvec;

class Shard {
 public:
  cvec slots;
  int n;

  // Initialize a Shard given a sequence of N N-character strings.
  Shard(vector<string> strings) {
    cvec slots;
    int n = strings.size();
    for (int i = 0; i < strings.size(); ++i) {
      for (int j = 0; j < strings.size(); ++j) {
        if (strings[i][j] == '#') {
          slots.push_back(make_pair(i, j));
        }
      }
    }
    this->n = n;
    this->slots = slots;  // Corrected: Assign to member variable
  }

  Shard(cvec slots) {
    this->slots = slots;
    this->n = slots.size();
  }
  /* Returns `true` if we can move the structure `(dx, dy)` units without any
   * conflicts and `false` otherwise. */
  bool can_move(int dx, int dy) {
    for (auto slot : slots) {
      if ((slot.first + dx < 0 || slot.first + dx > n) ||
          (slot.second + dy < 0 || slot.second + dy > n)) {
        return false;
      }
    }
    return true;
  }

  cvec possible_moves() {
    cvec result;
    for (int i = -n; i <= n; ++i) {
      for (int j = -n; j <= n; ++j) {
        if (can_move(i, j)) {
          result.push_back(make_pair(i, j));
        }
      }
    }
    return result;
  }

  Shard move(int dx, int dy) {
    vector<pair<int, int>> new_slots;
    for (auto slot : slots) {
      new_slots.push_back(make_pair(slot.first + dx, slot.second + dy));
    }
    return Shard(new_slots);
  }

  // Checks if two shards are mutually exclusive
  bool can_overlap(Shard other) {
    for (auto other : other.slots) {
      if (find(slots.begin(), slots.end(), other) != slots.end()) {
        return false;
      }
    }
    return true;
  }

  Shard superimpose(Shard other) {
    vector<pair<int, int>> new_slots(slots.size() + other.slots.size());
    for (int i = 0; i < slots.size(); ++i) {
      new_slots[i] = slots[i];
    }
    for (int i = slots.size(); i < slots.size() + other.slots.size(); ++i) {
      new_slots[i] = other.slots[i];
    }
    Shard new_shard = Shard(new_slots);
    new_shard.order_slots();
    return new_shard;
  }

  void order_slots() { sort(slots.begin(), slots.end()); }

bool operator==(const Shard& other) const {
  if (slots.size() != other.slots.size()) return false;

  // Make sorted copies to handle order invariance
  cvec sorted_slots = slots;
  sort(sorted_slots.begin(), sorted_slots.end());
  
  cvec sorted_other = other.slots;
  sort(sorted_other.begin(), sorted_other.end());

  // Compute the shift (dx, dy) from the first pair
  pair<int, int> shift = make_pair(
      sorted_slots[0].first - sorted_other[0].first,
      sorted_slots[0].second - sorted_other[0].second
  );

  // Verify all other pairs have the same shift
  for (size_t i = 1; i < sorted_slots.size(); ++i) {
    int dx = sorted_slots[i].first - sorted_other[i].first;
    int dy = sorted_slots[i].second - sorted_other[i].second;
    if (dx != shift.first || dy != shift.second) {
      return false;
    }
  }

  return true;
}
};

int main() {
  freopen("bcs.in", "r", stdin);
  int n;
  int k;
  cin >> n >> k;

  // Create an empty vector and reserve space if needed
  vector<Shard> shards;
  shards.reserve(k+1);  // Optional: Pre-allocate memory

  for (int i = 0; i < k+1; ++i) {
    vector<string> strings;
    for (int j = 0; j < n; ++j) {
      string x;
      cin >> x;
      strings.push_back(x);
    }
    shards.push_back(Shard(strings));  // Construct Shard and add to vector
  }

  for (int i = 0; i < k+1; ++i) {
    cout << i << ": ";
    for (auto pair : shards[i].possible_moves()) {
      cout << "(" << pair.first << ", " << pair.second << ") "; 
    }
    cout << endl;
  }

  // Double loop through all shards
  for (int i = 1; i < shards.size(); ++i) {
    Shard shard1 = shards[i];
    for (int j = 1; j < shards.size(); ++j) {
      Shard shard2 = shards[j];

      // Loop through all of the possible shifts of shard1
      for (auto move1 : shard1.possible_moves()) {
        // temp_shard is shard1 shifted
        Shard moved_shard1 = shard1.move(move1.first, move1.second);
        for (auto move2 : shard2.possible_moves()) {
          Shard moved_shard2 = shard2.move(move2.first, move2.second);

          cout << endl;
          cout << i << " shifted (" << move1.first << ", " << move1.second << ")" << endl;
          cout << j << " shifted (" << move2.first << ", " << move2.second << ")" << endl;
          cout << i << ": ";
          for (auto pair : moved_shard1.slots) {
            cout << "(" << pair.first << ", " << pair.second << ") "; 
          }
          cout << endl;
          cout << j << ": ";
          for (auto pair : moved_shard2.slots) {
            cout << "(" << pair.first << ", " << pair.second << ") "; 
          }
          cout << endl;
          // Check if the two shards can overlap
          if (moved_shard1.can_overlap(moved_shard2)) {
            Shard new_shard = moved_shard1.superimpose(moved_shard2);
            cout << "Superimposing..." << endl;
            if (new_shard == shards[0]) {
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
              cout << "FOUND AT i=" << i << ", j=" << j << endl;
            }
          }
        }
      }
    }
  }

  return 0;
}

