#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

long long nxt() {
	long long n; cin >> n; return n;
}

bool is_prime(int num) {
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    // Check for divisibility from 2 up to the square root of num
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; // If divisible, it's not prime
        }
    }
    return true; // If no divisors found, it's prime
}

int main() {
	// freopen("i", "r", stdin);
	int n = nxt();

	for (int i = 0; i < n; ++i) {
		auto x = nxt();
		// cout << x << " | " << sqrt(x) << endl;
		long long s = round(sqrt(x));
		// cout << s << endl;
		if (s * s == x && is_prime(s)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}