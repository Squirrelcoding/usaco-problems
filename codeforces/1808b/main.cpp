#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

long long nxt() {
    long long x;
    cin >> x;
    return x;
}

long long solve(vector<vector<long long>>& cards, long long n, long long m) {
    long long s = 0;
    
    // Iterate over columns
    for (long long column = 0; column < m; ++column) {
        vector<long long> col_values(n);
        
        // Extract values from each row for this column
        for (long long row = 0; row < n; ++row) {
            col_values[row] = cards[row][column];
        }
        
        // Sort column values
        sort(all(col_values));
        
        // Apply formula
        for (long long i = 1; i <= n; ++i) {
            s += col_values[i - 1] * (2 * i - n - 1);
        }
    }
    return s;
}

vector<vector<long long>> get_cards() {
    long long n = nxt();
    long long m = nxt();
    
    // Store cards row-wise
    vector<vector<long long>> cards(n, vector<long long>(m, 0));

    // Read input correctly
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cards[i][j] = nxt();
        }
    }
    
    return cards;
}

int main() {
    long long t = nxt();
    
    for (long long i = 0; i < t; ++i) {
        vector<vector<long long>> cards = get_cards();
        cout << solve(cards, cards.size(), cards[0].size()) << endl;
    }

    return 0;
}

