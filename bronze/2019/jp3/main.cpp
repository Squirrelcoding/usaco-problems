#include <bits/stdc++.h>

using namespace std;

struct animal {
  string name{};
  vector<string> characteristics{};

  // Equality operator
  bool operator==(const animal& other) const {
    return name == other.name;
  }
};

// Custom hash function for animal
struct animal_hash {
  size_t operator()(const animal& a) const {
    return hash<string>()(a.name);
  }
};

int main() {
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);

  int n;
  cin >> n;

  unordered_set<animal, animal_hash> animals;

  for (int i = 0; i < n; ++i) {
    string name;
    int len;
    vector<string> characteristics;
    cin >> name >> len;

    for (int j = 0; j < len; ++j) {
      string characteristic;
      cin >> characteristic;
      characteristics.push_back(characteristic);
    }
    animals.insert({name, characteristics});
  }

  unordered_map<string, unordered_set<string>> animal_to_characteristic;
  unordered_map<string, unordered_set<string>> characteristic_to_animal;
  
  // Construct the stuff.
  for (auto animal : animals) {
    if (animal_to_characteristic.find(animal.name) == animal_to_characteristic.end()) {
    }
  }


  return 0;
}
