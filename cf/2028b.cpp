#pragma GCC optimize("O3")

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

		ll n, b, c;
		cin >> n >> b >> c;

		if (b == 0) {
			if (n - c > 2) {
				cout << -1 << endl;
			} else if (n - c <= 0) {
				cout << n << endl;
			} else {
				cout << n - 1 << endl;
			}
			continue;
		}

		if (c >= n) {
			cout << n << endl;
			continue;
		}

		// ans = n - number of overlaps
		ll overlaps = 1 + ((n - c - 1) / b);
		ll ans = max(n - overlaps, 0ll);
		cout << ans << endl;

	}
}
