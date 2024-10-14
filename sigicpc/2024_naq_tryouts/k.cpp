#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main() {

	int n, m; cin >> n >> m;

	vector<int> expected;
	vector<int> actual;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		expected.push_back(x);
	}
	
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		actual.push_back(x);
	}

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			int diff = abs(expected[i - 1] - actual[j - 1]);
			
			int include_value = dp[i - 1][j - 1];
			if (diff <= 15) {
				include_value += 7;
			} else if (diff <= 23) {
				include_value += 6;
			} else if (diff <= 43) {
				include_value += 4;
			} else if (diff <= 102) {
				include_value += 2;
			}

			dp[i][j] = max(include_value, max(dp[i - 1][j], dp[i][j - 1]));
		}
	}

	cout << dp[n][m] << endl;

}
