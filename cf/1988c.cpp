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
		ll n; cin >> n;
		int i = 0;
		vll ans;
		while ((1ll << i) <= n) {
			ll val = 1ll << i;
			if (n & val) {
				ans.push_back(n - val);
			}
			i++;
		}
		reverse(all(ans));
		if (ans.size() == 1) {
			cout << 1 << endl << n << endl;
			continue;
		}

		ans.push_back(n);
		cout << ans.size() << endl;
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
}
