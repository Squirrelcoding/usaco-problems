#include <bits/stdc++.h>

using namespace std;

enum Direction {
  N,
  E,
  S,
  W
};


// Specialize std::hash for std::pair<int, int>
namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            auto hash1 = hash<int>{}(p.first);
            auto hash2 = hash<int>{}(p.second);
            return hash1 ^ (hash2 << 1);
        }
    };
}


int main() {
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);
  int n;
  cin >> n;


  vector<pair<Direction, int>> movements;

  for (int i = 0; i < n; i++) {
    char d; int amount;
    cin >> d >> amount;
    Direction direction;

    if (d == 'N') {
      direction = Direction::N;
    }
    if (d == 'E') {
      direction = Direction::E;
    }
    if (d == 'S') {
      direction = Direction::S;
    }
    if (d == 'W') {
      direction = Direction::W;
    }

    movements.push_back(make_pair(direction, amount));
  }

  unordered_map<pair<int, int>, vector<int>> visited_squares;
  visited_squares[make_pair(0, 0)] = {0};

  pair<int ,int> current_position = {0, 0};

  int t = 0;
  for (auto movement : movements) {
    for (int i = 0; i < movement.second; ++i) {
      t += 1;
      if (movement.first == Direction::N) {
        current_position.first += 1;
      }

      if (movement.first == Direction::S) {
        current_position.first -= 1;
      }

      if (movement.first == Direction::E) {
        current_position.second += 1;
      }

      if (movement.first == Direction::W) {
        current_position.second -= 1;
      }
      if (visited_squares.find(current_position) == visited_squares.end()) {
        visited_squares[current_position] = {t};
      } else {
        visited_squares[current_position].push_back(t);
      }
    }
  }

  // Check if all of the vectors are of length 1, in which case we return -1.
  bool are_all_one = true;
  for (auto seq : visited_squares) {

    if (seq.second.size() > 1) {
      are_all_one = false;
      break;
    }
  }


  if (are_all_one) {
    cout << "-1" << endl;
  } else {
    int smallest_difference = numeric_limits<int>::max();

    for (auto seq : visited_squares) {
      if (seq.second.size() == 1) {
        continue;
      }
      // Loop through the differences
      for (int i = 0; i + 1 < seq.second.size(); ++i) {
        smallest_difference = min(smallest_difference, seq.second[i+1] - seq.second[i]);
      }
    }

    cout << smallest_difference << endl;
  }


  return 0;
}
