#include <bits/stdc++.h>

using namespace std;
typedef tuple<string, string, string, string> info;

map<string, int> years = {
  {"Ox", 0},
  {"Tiger", 1},
  {"Rabbit", 2},
  {"Dragon", 3},
  {"Snake", 4},
  {"Horse", 5},
  {"Goat", 6},
  {"Monkey", 7},
  {"Rooster", 8},
  {"Dog", 9},
  {"Pig", 10},
  {"Rat", 11},
};

int calculate_years(string& previous_or_next, string& year1, string& year2) {
  // Cow1 was born in the previous year1 from year2
  if (previous_or_next == "previous") {
    if (years[year1] > years[year2]) {
      return -(years[year2] + (12-years[year1]));
    } else if (years[year1] == years[year2]) {
      return -12; 
    } else {
      return years[year1] - years[year2];
    }
  } else {
    // Cow1 was born in the next year1 from year2
    if (years[year2] < years[year1]) {
      return years[year1] - years[year2]; 
    } else if (years[year1] == years[year2]) {
      return 12;
    }
    else {
      // Cow 1 was born in the next year1 year from year2
      return years[year1] + (12 - years[year2]);
    }
  }
}

int main() {
  /*freopen("input", "r", stdin);*/
  unordered_map<string, pair<int, string>> cows;
  cows["Bessie"] = {0, "Ox"};

  int n; cin >> n;
  cin.ignore();

  vector<info> information(n);

  for (int i = 0; i < n; ++i) {
    string cow1;
    cin >> cow1;
    cin.ignore(8);
    string previous_or_next;
    cin >> previous_or_next;
    string year;
    cin >> year;
    cin.ignore(10);
    string cow2;
    cin >> cow2;
    information[i] = {cow1, previous_or_next, year, cow2};
  }

  string current_year;

  for (auto info : information) {
    // Find information for cow2
    current_year = cows[get<3>(info)].second;
    int res = calculate_years(get<1>(info), get<2>(info), current_year);
    cows[get<0>(info)] = {cows[get<3>(info)].first + res, get<2>(info)};

    if (get<0>(info) == "Elsie") {
      break;
    }
  }

  cout << abs(cows["Elsie"].first) << endl;

  return 0;
}
