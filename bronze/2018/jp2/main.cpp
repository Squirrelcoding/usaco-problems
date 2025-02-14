#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // Include this for the max function


using namespace std;

typedef pair<int, int> shift;

int main() {
  freopen("lifeguards.in", "r", stdin);

  int n;
  cin >> n;

  vector<shift> shifts(n);

  for (int i = 0; i < n; ++i) {
    int a; int b;
    cin >> a >> b;
    shifts[i] = make_pair(a, b);
  }

  unordered_set<int> times;

  for (auto shift : shifts) {
    for (int i = shift.first; i <= shift.second; ++i) {
      times.insert(i);
    }
  }

  int max_time = 0;
  for (auto shift : shifts) {
    // Remove the times in shift from times
    for (int i = shift.first; i <= shift.second; ++i) {
      times.erase(i);
    }
    max_time = max(max_time, static_cast<int>(times.size()));

    for (int i = shift.first; i <= shift.second; ++i) {
      times.insert(i);
    }
  }

  cout << max_time << endl;

  return 0;
}
