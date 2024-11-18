#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1000000007;

ll pow_mod(ll x, ll exp) {
	if (exp <= 0) { return 1; }
	ll t = pow_mod(x, exp / 2);
	if (exp % 2 == 0) {
		return (t * t) % MOD;
	} else {
		return (((t * t) % MOD) * x) % MOD;
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	while (t--) {
		int l, r, k;
		cin >> l >> r >> k;

		ll base = 0;
		if (k == 1) {
			base = 10;
		} else if (k == 2) {
			base = 5; // 0, 1, 2, 3, 4
		} else if (k == 3) {
			base = 4; // 0, 1, 2, 3
		} else if (k == 4) {
			base = 3;
		} else if (k <= 9) {
			base = 2;
		}

		if (base == 0) {
			cout << 0 << endl;
			continue;
		}
		ll ans = pow_mod(base, r) - pow_mod(base, l);
		if (ans < 0) { ans += MOD; }
		cout << ans << endl;
	}
}
