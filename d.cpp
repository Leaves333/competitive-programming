#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> intervals;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		intervals.push_back(make_pair(a, b));
	}
	sort(intervals.begin(), intervals.end(), greater<pair<int, int>>());

	int dp[m];
	memset(dp, 0, sizeof(dp));
	dp[m - 1] = m;
	int idx = m - 1;
	for (int i = 0; i < n; i++) {
		auto cur = intervals[i];
		while (idx > cur.first - 1) {
			idx--;
			dp[idx] = dp[idx + 1];
		}

		dp[idx] = min(dp[idx], cur.second - 1);
	}

	cout << 2 << " | " << dp[2] << endl;
	cout << 1 << " | " << dp[1] << endl;
	cout << 0 << " | " << dp[0] << endl;

	long long ans = 0;
	for (int i = 0; i < m; i++) {
		ans += dp[i] - i;
	}
	cout << ans << endl;
}
