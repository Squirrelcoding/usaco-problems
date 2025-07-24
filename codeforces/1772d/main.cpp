#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
    int n; cin >> n; return n;
}

int main() {
    // freopen("input", "r", stdin);
    int t = nxt();
    for (int y = 0; y < t; ++y) {
        int n = nxt();
        vector<int> nums(n);
        generate(all(nums), nxt);
        
        int lower = -1;
        int upper = 100000000;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                upper = min(upper, (nums[i] + nums[i + 1]) / 2);
            } 
            if (nums[i + 1] < nums[i]) {
                lower = max(lower, (nums[i] + nums[i + 1] + 1) / 2);
            }
        }
        if (upper < lower) cout << -1 << endl;
        else {
            cout << (lower + upper) / 2 << endl;
        }
    }
    return 0;
}