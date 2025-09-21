#include<bits/stdc++.h>

using namespace std;

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	// freopen("i", "r", stdin);
	int n = nxt();
	map<string, int> names;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		if (names.count(s) == 0) {
			cout << "OK" << endl;
			names[s] = 1;
		} else {
			cout << s << names[s] << endl;
			names[s] = names[s] + 1;
		}
	}
	return 0;
}