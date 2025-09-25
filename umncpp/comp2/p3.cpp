#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)

int nxt() {
	int n; cin >> n; return n;
}

int main() {
	// freopen("i", "r", stdin);

	int t = nxt();

	for (int i = 0; i < t; ++i) {
		int max_sum = INT_MIN;
		int n = nxt();
		int m = nxt();
		vector<int> nums(n);
		generate(all(nums), nxt);

		// cout << "HERE" << endl;

		// Locate all of the locations of m
		vector<int> m_indices;
		for (int j = 0; j < n; ++j) {
			if (nums[j] == m) m_indices.push_back(j);
		}


		// For each m, expand to the left and to the right
		for (int j = 0; j < m_indices.size(); ++j) {
			int current_sum = m;

			// Expand to the left
			int left_idx = m_indices[j] - 1;
			while (left_idx >= 0 && m < nums[left_idx]) {
				current_sum += nums[left_idx];
				left_idx--;
			}

			int right_idx = m_indices[j] + 1;
			while (right_idx < n && m < nums[right_idx]) {
				current_sum += nums[right_idx];
				right_idx++;
			}
			max_sum = max(max_sum, current_sum);
		}
		cout << max_sum << endl;
	}


	return 0;
}