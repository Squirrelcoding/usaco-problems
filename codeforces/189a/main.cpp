#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	freopen("i", "r", stdin);

	int n = nxt();
	int a = nxt();
	int b = nxt();
	int c = nxt();

	set<tuple<int, int, int>> pairs;

	int r = INT_MAX;

	for (int x = 0; x <= n; ++x) {
		for (int y = 0; y <= n; ++y) {
			for (int z = 0; z <= n; ++z) {
				if (pairs.count({x,y,z}) > 0) continue;
				pairs.insert({x,y,z});
				if (a*x + b*y + c*z == n) {
					r = max(r, x + y + z);
				}
			}
		}
	}

	cout << r << endl;

	return 0;
}