#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	while (t--) {
		int n, m, k, d;
		cin >> n >> m >> k >> d;

		// how do we calculate the cost for a single bridge?
		// then its a simple o(n) prefix sum to get the best supports

		// observations: clearly dp
		// brute force: o(md). not good
		// but we can do o(m logd)!!! by using a heap to find the min

		vll costs(n);
		for (int i = 0; i < n; i++) {
			vll heights(m);
			for (int j = 0; j < m; j++) {
				cin >> heights[j];
			}

			vll dp(m); // stores cost to have a support built at i
			dp[0] = 1;
			multiset<ll> previous;
			previous.insert(1);
			for (int j = 1; j < m; j++) {
				dp[j] = *previous.begin() + heights[j] + 1;
				previous.insert(dp[j]);
				if (j > d) {
					auto left_value = dp[j - d - 1];
					previous.erase(previous.find(dp[j - d - 1]));
				}
			}

			// calculate dp array...
			costs[i] = dp[m - 1];
		}

		vll psum(n + 1);
		for (int i = 0; i < n; i++) {
			psum[i + 1] = psum[i] + costs[i];
		}

		ll ans = LLONG_MAX;
		for (int i = k; i < n + 1; i++) {
			ans = min(ans, psum[i] - psum[i - k]);
		}
		cout << ans << endl;
	}
}
