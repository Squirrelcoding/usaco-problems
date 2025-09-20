#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	// freopen("input", "r", stdin);
	int n = nxt();
	vector<int> nums(n);
	generate(all(nums), nxt);

	int a = nums[0];
	int b = nums[1];
	int c = nums[2];

	int par = 0;

	// All equal
	if (a % 2 == b % 2 && b % 2 == c % 2) {
		par = a % 2;
	}

	// c is different
	if (a % 2 == b % 2 && b % 2 != c % 2) {
		cout << 3 << endl;
		return 0;
	}

	// a is different
	if (c % 2 == b % 2 && b % 2 != a % 2) {
		cout << 1 << endl;
		return 0;
	}

	// b is different
	if (a % 2 == c % 2 && c % 2 != b % 2) {
		cout << 2 << endl;
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		if (nums[i] % 2 != par) {
			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}