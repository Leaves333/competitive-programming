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
		int n, m;
		cin >> n >> m;
		vi a(n);
		vi b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		ll base = 0;
		for (int i = n - 1; i >= m; i--) {
			base += min(a[i], b[i]);
		}

		ll chain = a[m - 1];
		ll psum = 0;
		for (int i = m - 1; i > 0; i--) {
			psum += b[i];
			chain = min(chain, psum + a[i - 1]);
		}

		cout << base + chain << endl;
	}
}
