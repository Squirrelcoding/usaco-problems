#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
    int n; cin >> n; return n;
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    int n = nxt();
    vector<pair<int, int>> cows;

    for (int i = 0; i < n; ++i) {
        int x = nxt();
        int y = nxt();
        cows.push_back({x, y});
    }
    pair<int, int> avg = {0, 0};
    for (auto cow : cows) {
        avg.first += cow.first;
        avg.second += cow.second;
    }
    avg.first /= cows.size();
    avg.second /= cows.size();

    sort(all(cows), [avg](const pair<int, int>& p1, const pair<int, int>& p2) {
        return (abs(p1.first - avg.first) + abs(p1.second - avg.second)) < (abs(p2.first - avg.first) + abs(p2.second - avg.second));
    });

    int min_x = 2147483647;
    int max_x = -2147483647;
    int min_y = 2147483647;
    int max_y = -2147483647;

    // Calculate the area without the 3 biggest ones
    for (int i = 0; i < cows.size() - 3; ++i) {
        min_x = min(min_x, cows[i].first);
        max_x = max(max_x, cows[i].first);
        min_y = min(min_y, cows[i].second);
        max_y = max(max_y, cows[i].second);
    }

    cout << (max_x - min_x) * (max_y - min_y) << endl;

    return 0;
}