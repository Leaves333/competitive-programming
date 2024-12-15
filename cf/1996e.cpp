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

	const ll mod = 1000000007;
	int t; cin >> t;
	while (t--) {

		string s; cin >> s;
		vi ones(s.length() + 1);
		for (int i = 0; i < s.length(); i++) {
			ones[i + 1] = ones[i] + (1 * (s[i] == '1' ? 1 : -1));
		}

		ll ans = 0;
		map<int, ll> m; // map value to sum of indices
		for (int i = 0; i < s.length(); i++) {
			m[ones[i]] += i + 1;
			ans += ((ll) m[ones[i + 1]]) * (s.length() - i);
			ans %= mod;
		}

		cout << ans << endl;

	}
}
