#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // Include this for the max function

using namespace std;

typedef pair<int, int> shift;

int main() {
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n;
  cin >> n;

  vector<shift> shifts(n);

  int latest_time = 0;

  for (int i = 0; i < n; ++i) {
    int a; int b;
    cin >> a >> b;
    latest_time = max(latest_time, max(a, b));
    shifts[i] = make_pair(a, b);
  }


  unordered_map<int, int> times;
  for (int i = 0; i < latest_time; ++i) {
    times[i] = 0;
  }

  for (auto shift : shifts) {
    for (int i = shift.first; i < shift.second; ++i) {
      times[i]++;
    }
  }
  
  int max_time = 0;
  for (auto shift : shifts) {
    int s = 0;

    // Remove the shift.
    for (int i = shift.first; i < shift.second; ++i) {
      times[i]--;
    }
    for (int i = 0; i < latest_time; ++i) {
      if (times[i] > 0) {
        s += 1;
      }
    }
    for (int i = shift.first; i < shift.second; ++i) {
      times[i]++;
    }

    // Count the number of times there is a nonzero entry.
    max_time = max(max_time, s);
  }

  cout << max_time << endl;

  return 0;
}
