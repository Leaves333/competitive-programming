#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll pow_mod(ll x, ll n, ll m) {
	if (n == 0) { return 1; }
	ll t = pow_mod(x, n / 2, m);
	if (n % 2 == 0) {
		return (t * t) % m;
	} else {
		return (((t * t) % m) * x) % m;
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	const ll MOD = 1000000007;
	vll factorial(300001);
	vll inverse(300001);

	factorial[0] = 1;
	for (int i = 1; i < 300001; i++) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	for (int i = 0; i < 300001; i++) {
		inverse[i] = pow_mod(factorial[i], MOD - 2, MOD);
	}

	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int slots = n;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			if (a == b) {
				slots -= 1;
			} else {
				slots -= 2;
			}
		}

		ll ans = 0;
		for (int r = 0; r <= slots; r += 2) {
			ll k = slots - r;

			ll choose = factorial[slots] * inverse[k];
			choose %= MOD;
			choose *= inverse[slots - k];
			choose %= MOD;

			ll combs = factorial[r] * inverse[r / 2];
			combs %= MOD;

			ans += (choose * combs) % MOD;
			ans %= MOD;
		}

		cout << ans << endl;

	}
}
