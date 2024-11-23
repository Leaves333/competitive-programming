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
		int n; cin >> n;

		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += i * ((2 * i - 2) + 1);
		}

		cout << ans << " " << 2 * n << endl;
		for (int i = n; i > 0; i--) {
			cout << 1 << " " << i << " ";
			for (int j = 1; j <= n; j++) {
				cout << j << " ";
			}
			cout << endl;
			cout << 2 << " " << i << " ";
			for (int j = 1; j <= n; j++) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
}
