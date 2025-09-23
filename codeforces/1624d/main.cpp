#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 2e5;

int main(int argc, char* argv[]) {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int cntPairs = 0, cntOdd = 0;
        for (int c : cnt) {
            cntPairs += c / 2;
            cntOdd += c % 2;
        }
        int ans = 2 * (cntPairs / k);
        cntOdd += 2 * (cntPairs % k);
        if (cntOdd >= k) {
            ans++;
        }
        cout << ans << '\n';
    }
}