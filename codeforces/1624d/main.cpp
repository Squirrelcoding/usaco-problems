#include<iostream>
#include<map>
#include<vector>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
    int n; cin >> n; return n;
}

int main() {
    freopen("input", "r", stdin);
    int t = nxt();
    for (int a = 0; a < t; ++a) {
        int n = nxt();
        int k = nxt();
        string s;
        cin >> s;
        map<char, int> char_map;
        for (char c : s) {
            if (char_map.count(c)) {
                char_map[c]++;
            } else {
                char_map[c] = 1;
            }
        }
        int double_char_count = 0;
        int m = 0;
        int coun = 0;

        for (auto p : char_map) {
            coun++;
            double_char_count += p.second / 2;
            if (double_char_count > 0) coun++;
            if (p.second % 2 == 1) m += 1;
        }
        if (m >= k) {
            cout << coun / k + 1 << endl;
        } else {
            cout << coun / k << endl;
        }
    }
    return 0;
}