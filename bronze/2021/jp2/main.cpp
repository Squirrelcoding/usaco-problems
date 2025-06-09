// Taken from editorial

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int even = 0;
	int odd = 0;
	for (int i = 0; i < n; i++) {
		int cow;
		cin >> cow;
		if (cow % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	}

	// Pair up odd cows so that there aren't too many of them.
	while (odd > even) {
		odd = odd - 2;
		// Two odd cows together are effectively an even cow.
		even++;
	}
	// Group even cows so that there aren't too many evens either.
	if (even > odd + 1) { even = odd + 1; }

	cout << odd + even << endl;
}