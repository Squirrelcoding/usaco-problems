#include<bits/stdc++.h>

using namespace std;

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	// freopen("input", "r", stdin);
	int t = nxt();

	for (int i = 0; i < t; ++i) {
		int n = nxt();
		int k = nxt();

		// cout << "k = " << k << " n = " << n << endl;
		int start = (k-1) % (n-1) + 1;
		int multiple = (k - start) / (n-1);
		// cout << "start = " << start << "multiple = " << multiple << endl;

		cout << multiple*n + start << endl;
	}

	return 0;
}