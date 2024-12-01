#pragma GCC optimize("O3")
#pragma GCC target("avx2")

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
		vi a(n);
		vi b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		int rating_a = 0;
		int rating_b = 0;
		int pos = 0;
		int neg = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				pos += (a[i] == 1);
				neg += (a[i] == -1);
			} else {
				if (a[i] < b[i]) {
					rating_b += b[i];
				} else {
					rating_a += a[i];
				}
			}
		}

		int ans = INT_MIN;
		for (int i = neg * -1; i <= pos; i++) {
			ans = max(ans, min(rating_a + i, rating_b + pos - neg - i));
		}
		cout << ans << endl;
	}
}
