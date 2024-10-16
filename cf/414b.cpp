#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	const int MOD = 1000000007;

	// dp[i][j] stores number of sequences ending with i, containing j elements
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n + 1; i++) {
		dp[i][1] = 1;
	}

	// i = last number
	for (int i = 1; i < n + 1; i++) {
		// j = length of sequence
		for (int j = 1; j < k; j++) {
			// multiply i by a number of times
			for (int new_last = i; new_last < n + 1; new_last += i) {
				dp[new_last][j + 1] += dp[i][j];
				dp[new_last][j + 1] %= MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		ans += dp[i][k];
		ans %= MOD;
	}
	cout << ans << endl;

}
