#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find the longest sorted suffix
    int sorted_start = n - 1;
    while (sorted_start > 0 && nums[sorted_start - 1] < nums[sorted_start]) {
        sorted_start--;
    }

    // The number of moves needed is exactly sorted_start
    cout << sorted_start << endl;
    return 0;
}

