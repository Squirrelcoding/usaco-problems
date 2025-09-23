#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end (x)


long long nxt() {
	long long n; cin >> n; return n;
}

int main() {
	long long n = nxt();
	long long x = 0;
	long long y = 0;
	long long z = 0;
	for (long long i = 0; i < n; ++i) {
		long long xi = nxt();
		long long yi = nxt();
		long long zi = nxt();
		x += xi;
		y += yi;
		z += zi;
	}

	if (x == 0 && y == 0 && z == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl; 
	}

	return 0;
}
