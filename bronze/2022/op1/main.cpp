#include <bits/stdc++.h>

using namespace std;


#define all(x) begin(x), end(x)

int nxt() {
  int n; cin >> n; return n;
}

enum GType {
  TWO_G,
  EVEN_G,
  ODD_G,
  NO_G
};

int main() {
  /*freopen("input", "r", stdin);*/
  int n = nxt();
  string input;
  cin >> input;

  vector<GType> data; 

  for (int i = 0; i < n; i += 2) {
    char first_char = input[i];
    char second_char = input[i + 1];
    if (first_char == second_char && first_char == 'H') {
      data.push_back(GType::NO_G);
    } else if (first_char == second_char && first_char == 'G') {
      data.push_back(GType::TWO_G);
    } else if (first_char == 'G' && second_char == 'H') {
      data.push_back(GType::ODD_G);
    } else {
      data.push_back(GType::EVEN_G);
    }
  }



  int step_counter = 0;
  for (int i = data.size() - 1; i >= 0; --i) {
    // Check status of current element 
    GType current = data[i];
    if (current == GType::ODD_G) {
      ++step_counter;
      /*cout << "At i = " << i << " we are flipping." << endl;*/
      // Reverse all of the cows up to and including i
      for (int j = 0; j <= i; ++j) {
        switch (data[j]) {
          case GType::ODD_G:
            data[j] = GType::EVEN_G;
            break;
          case GType::EVEN_G:
            data[j] = GType::ODD_G;
            break;
          default:
            continue;
        }
      }
      /**/
      /*for (GType g : data) {*/
      /*  cout << g << endl;*/
      /*}*/
      /**/
      /*cout << endl;*/
      /*cout << endl;*/
      /*cout << endl;*/
      /*cout << endl;*/
      /*cout << endl;*/
    } 
  }

  cout << step_counter << endl;

  return 0;
}
