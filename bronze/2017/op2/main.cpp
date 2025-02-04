#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  int n; int m;
  cin >> n >> m;

  vector<string> spotty_cows;
  vector<string> plain_cows;

  unordered_set<char> genomes = {'A', 'C', 'G', 'T'};
  
  for (int i = 0; i < n; ++i) {
    string input;
    cin >> input;
    spotty_cows.push_back(input);
  }

  for (int i = 0; i < n; ++i) {
    string input;
    cin >> input;
    plain_cows.push_back(input);
  }

  // Begin the loop. Start by assuming that ALL of the genomes can be used to explain spottiness.
  // Then, if we find a genome (A, C, G, T) that is present in both, we mark it as NOT being useful.
  // Finally, we if ANY of the variables are true, we add one to our counter;
  // Actually, we should account for the fact that not all of the genomes will appear.

  int counter = 0;
  for (int i = 0; i < m; ++i) {
    // Loop through the genomes in position i of the spotty cows and mark them.
    set<char> spotty_genome = {};
    set<char> plain_genome = {};

    for (int row = 0; row < n; ++row) {
      spotty_genome.insert(spotty_cows[row][i]);
    }

    for (int row = 0; row < n; ++row) {
      plain_genome.insert(plain_cows[row][i]);
    }

    // If the intersection is not empty, it's impossible to tell.
    // If this test is passed, we just have to check if each set has exactly one unique character.
    vector<char> intersection;

    set_intersection(
      spotty_genome.begin(), spotty_genome.end(),
      plain_genome.begin(), plain_genome.end(),
      back_inserter(intersection)
    );

    if (intersection.size() == 0) {
      ++counter;
    }

  }

  cout << counter << endl;

  return 0;
}
