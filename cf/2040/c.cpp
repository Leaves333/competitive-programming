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

		ll n, k;
		cin >> n >> k;

		if (n < 41 && k > (1ll << (n - 1))) {
			cout << -1 << endl;
			continue;
		}

		set<int> values_increasing;
		set<int> values_decreasing;
		for (int i = 1; i < n; i++) {
			values_increasing.insert(i);
		}
		values_decreasing.insert(n);

		k--;
		for (int i = 0; i < min(50ll, n - 1); i++) {
			if (k & (1ll << i)) {
				values_increasing.erase(n - i - 1);
				values_decreasing.insert(n - i - 1);
			}
		}

		for (auto it = values_increasing.begin(); it != values_increasing.end(); it++) {
			cout << *it << " ";
		}

		auto it = values_decreasing.end();
		it--;
		bool good = true;
		while (good) {
			if (it == values_decreasing.begin()) {
				good = false;
			}
			cout << *it << " ";
			it--;
		}
		cout << endl;
	}
}
