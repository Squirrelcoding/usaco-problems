#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	freopen("i", "r", stdin);

	int n = nxt();
	vector<int> nums(n);
	generate(all(nums), nxt);

	

	return 0;
}