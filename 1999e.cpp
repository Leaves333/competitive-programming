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
		int l, r;
		cin >> l >> r;

		int small = l;
		int exponent = 0;
		int threshold = 1;
		while (small > 0) {
			small /= 3;
			threshold *= 3;
			exponent++;
		}

		int ans = exponent;
		while (l <= r) {
			int nums = min(r, threshold - 1) - l + 1;
			ans += nums * exponent;
			l = threshold;
			exponent++;
			threshold *= 3;
		}

		cout << ans << endl;
	}
}
