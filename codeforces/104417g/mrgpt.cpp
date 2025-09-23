#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, vector<int>> groups;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int key = i - a[i];
            groups[key].push_back(a[i]);
        }

        ll total = 0;
        for (auto& [_, vec] : groups) {
            sort(vec.rbegin(), vec.rend()); // sort descending
            for (int i = 0; i + 1 < vec.size(); i += 2) {
                ll sum = ll(vec[i]) + vec[i + 1];
                if (sum < 0) break;
                total += sum;
            }
        }

        cout << total << '\n';
    }

    return 0;
}
