#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	while (b > 0) {
		ll t = b;
		b = a % b;
		a = t;
	}
	return a;
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
		}

		for (int x : arr) {
			cout << x << "\t";
		}
		cout << endl;

		for (int x : prefix_sum) {
			cout << x << "\t";
		}
		cout << endl;

		ll num_pairs = n * (n - 1) / 2;

		ll ans = 0;
		for (int i = 1; i < n; i++) {
			ll product = arr[i] * (prefix_sum[n] - prefix_sum[i]);
			ans += product;
			ans %= MOD;
		}

		cout << "ans: " << ans << endl;
		cout << "num pairs: " << num_pairs << endl;
		cout << ans / num_pairs << endl;
		cout << endl;
	}

}
