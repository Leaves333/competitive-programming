#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power_under_mod(ll x, ll n, ll m) {
	if (n == 0) {
		return 1;
	}

	ll t = power_under_mod(x, n / 2, m);
	if (n % 2 == 0) {
		return (t * t) % m;
	} else {
		return (((t * t) % m) * x) % m; 
	}
}

int main() {

	const ll MOD = 1000000007;
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {

		ll n; cin >> n;
		ll arr[n + 1];
		ll prefix_sum[n + 1];
		memset(arr, 0, sizeof(arr));
		memset(prefix_sum, 0, sizeof(prefix_sum));

		for (int i = 1; i < n + 1; i++) {
			cin >> arr[i];
			prefix_sum[i] = prefix_sum[i - 1] + arr[i];
			prefix_sum[i] %= MOD;
		}

		ll num_pairs = n * (n - 1) / 2;
		ll num_pairs_inverse = power_under_mod(num_pairs % MOD, MOD - 2, MOD);

		ll ans = 0;
		for (int i = 1; i < n; i++) {
			ll sum = prefix_sum[n] - prefix_sum[i];
			if (sum < 0) {
				sum += MOD;
			}
			ll product = arr[i] * sum;
			ans += product;
			ans %= MOD;
		}

		cout << (ans * num_pairs_inverse) % MOD << endl;
	}

}
