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
  /*freopen("guess.out", "w", stdout);*/ 
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


  unordered_map<string, unordered_set<animal, animal_hash>> characteristic_to_animal;
  
  // Construct the stuff.
  for (const auto& animal : animals) {
    for (const string& characteristic : animal.characteristics) {
      characteristic_to_animal[characteristic].insert(animal);
    }
  }
  /**/
  /*cout << " === Characteristics === " << endl;*/
  /*for (const auto& c: characteristic_to_animal) {*/
  /*  cout << c.first << ": ";*/
  /*  for (const auto& anim : c.second) {*/
  /*    cout << anim.name << " ";*/
  /*  }*/
  /*  cout << endl;*/
  /*}*/

  // Ok so we want to start a for loop where we select the characteristic with the highest number of animals in it.
  // In the animals set, we want to remove all of the animals in the current characteristic. While the set of animals
  // is greater than 1, we keep incrementing a counter.

  int counter = 0;
  while (animals.size() > 1) {
    // Find the characteristic with the most amount of animals in it.
    string most_common_characteristic;
    int max_amount = 0;
    for (const auto& keypair : characteristic_to_animal) {
      if (keypair.second.size() > max_amount) {
        most_common_characteristic = keypair.first;
        max_amount = keypair.second.size();
      }
    }
    cout << "The most common characteristic is " << most_common_characteristic << endl;

    vector<animal> to_be_deleted;

    for (const auto& animal : animals) {

      // Check if animal does NOT have the most common characteristic. In which case we delete it.
      if (find(
            animal.characteristics.begin(), 
            animal.characteristics.end(), 
            most_common_characteristic
          ) == animal.characteristics.end()) {
        
        // Go to each of the animal's other characteristics and delete it from there.
        for (const auto& other_char : animal.characteristics) {
          characteristic_to_animal[other_char].erase(animal);
        }

        // Remove the animal from the main set.
        to_be_deleted.push_back(animal);
      } 
    }

    for (auto animal : to_be_deleted) {
      animals.erase(animal);
    }

    // Delete the most common characteristic.
    characteristic_to_animal.erase(most_common_characteristic);

    counter++;
  }

  cout << counter << endl;

  return 0;
}
