#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<char, int>> constraints;
    vector<int> L_values, G_values;

    for (int i = 0; i < N; i++) {
        char type;
        int p;
        cin >> type >> p;
        constraints.push_back({type, p});

        if (type == 'L')
            L_values.push_back(p);
        else
            G_values.push_back(p);
    }

    // Sorting to efficiently find min L and max G
    sort(L_values.begin(), L_values.end());
    sort(G_values.begin(), G_values.end());

    int min_L = L_values.empty() ? 1e9 : L_values[0];  // Smallest L constraint
    int max_G = G_values.empty() ? 0 : G_values.back(); // Largest G constraint

    if (max_G > min_L) {
        // We need to remove cows to make an interval valid
        int min_lies = N; // Start with the worst case (all cows are lying)

        // Try each possible p (pivot) as a potential hiding spot
        for (const auto& [type, p] : constraints) {
            int lies = 0;

            // Count the number of lies if we assume Bessie hides at `p`
            for (const auto& [t, x] : constraints) {
                if ((t == 'G' && x > p) || (t == 'L' && x < p)) {
                    lies++; // This cow is lying
                }
            }
            min_lies = min(min_lies, lies);
        }

        cout << min_lies << "\n";
    } else {
        // If max_G <= min_L, all cows can be truthful
        cout << "0\n";
    }

    return 0;
}

