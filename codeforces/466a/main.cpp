#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

float nxt() {
	float n; cin >> n; return n;
}

int main() {
	float n = nxt();
	float m = nxt();
	float a = nxt();
	float b = nxt();

	float x = 0.0;
	float y = ceil(n - m * x);
	int result = INT_MAX;
	while (ceil(n - m * x) >= 0.0) {
		int t = b*x+a*y;
		result = min(result, t);
		x += 1.0;
		y = ceil(n - m * x);
	}
	// cout << "final b*x: " << b*x << endl;
	result = min(result, (int) (b*(x)));

	cout << result << endl;
	
	return 0;
}