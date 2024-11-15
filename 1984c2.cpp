#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	// precompute powers of 2...
	const ll MOD = 998244353;
	vector<ll> powers_of_two(300001);
	powers_of_two[0] = 1;
	for (int i = 1; i < 300001; i++) {
		powers_of_two[i] = (powers_of_two[i - 1] * 2) % MOD;
	}

	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		vector<ll> psum(n + 1);
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			psum[i] = psum[i - 1] + x;
		}

		ll min_val = -1;
		vector<ll> min_indices;
		for (int i = 1; i <= n; i++) {
			if (psum[i] < min_val) {
				min_val = psum[i];
				min_indices.clear();
				min_indices.push_back(i);
			} else if (psum[i] == min_val) {
				min_indices.push_back(i);
			}
		}

		if (min_indices.size() == 0) {
			cout << powers_of_two[n] << endl;
			continue;
		}

		vector<int> num_positive(n + 1);
		for (int i = 1; i <= n; i++) {
			num_positive[i] = num_positive[i - 1] + (int) (psum[i] >= 0);
		}
		
		ll ans = 0;
		for (auto x : min_indices) {
			ans += powers_of_two[n - x + num_positive[x]];
			ans %= MOD;
		}
		cout << ans << endl;

	}
}
