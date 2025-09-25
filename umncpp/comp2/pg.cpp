#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	freopen("i", "r", stdin);

	int t = nxt();

	vector<int> h_primes = {5, 9, 13, 17};

	set<int> sieve;

	// List of strategies
	// A sieve
	// idk


	for (int i = 0; i < t; ++i) {
		int h = nxt();
		// Generate the sieve up to h
		for (auto p : h_primes) {
			int k = 1;
			while (p*k < h) {
				sieve.insert(p*k);
			}
		}

	}

	return 0;
}