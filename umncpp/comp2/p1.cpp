#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	freopen("i", "r", stdin);

	string s; cin >> s;
	int a_points = 0;
	int b_points = 0;

	bool win_by_2_activated = false;

	for (int i = 0; i < s.size(); i += 2) {

		// Step through game
		if (s[i] == 'A') {
			if (s[i+1] == '1') {
				a_points += 1;
			} else {
				a_points += 2;
			}
		} else {			
			if (s[i+1] == '1') {
				b_points += 1;
			} else {
				b_points += 2;
			
			}
		}

		// Check win conditions

		if (win_by_2_activated) {
			if (a_points >= b_points + 2) {
				cout << "A" << endl;
				break;
			}
			if (b_points >= a_points + 2) {
				cout << "B" << endl;
				break;
			}
		} else {
			// 'activate' win-by-2 rule
			if (a_points == b_points && a_points == 10) {
				win_by_2_activated = true;
			}
			if (a_points >= 11) {
				cout << "A" << endl;
				break;
			}
			if (b_points >= 11) {
				cout << "B" << endl;
				break;
			}
		}

	}



	return 0;
}