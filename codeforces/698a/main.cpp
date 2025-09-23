#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

int nxt() {
	int n; cin >> n; return n;
}

int solve(vector<int> nums) {

	// Get the middle index

	// If the middle is 1, create two options with 0 and 1. Modify the neighbors accordingly.
	// If the middle is 2, create two options with 0 and 1. Modify the neighbors accordingly.
	// If the middle is 3, create three options with 0, 1, and 2. Modify the neighbors accordingly.

	// WAIT BUT THIS DOESNT EVEN ACCOUNT FOR THE OTHER CONDITIONS!!!

	int middle = nums.size() / 2;

	if (nums[middle] == 0) {
		// Split the nums
		vector<int> first;
		vector<int> second;
		for (int i = 0; i < middle; ++i) {
			first.push_back(nums[i]);
		}
		for (int i = middle + 1; i < nums.size(); ++i) {
			second.push_back(nums[i]);
		}
		return solve(first) + solve(second);
	}
	if (nums[middle] == 1) {

	}

	return 0;
}

int main() {
	freopen("input", "r", stdin);

	int n = nxt();
	vector<int> nums(n);
	fill(all(nums), nxt);

	// Split the nums vector into multiple ones where there are NO zeros

	// Call solve on each of them


	cout << solve(nums) << endl;

	return 0;
}