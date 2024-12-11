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

	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		if (k == 0) {
			for (int i = 0; i < n / 2; i++) {
				cout << i << " " << (i ^ (n - 1)) << endl;
			}
		} else if (k == n - 1) {
			if (n == 4) {
				cout << -1 << endl;
				continue;
			}
			// pair n-1 with n-2, n-3 with 1, 0 with 2
			cout << n-1 << " " << n-2 << endl;
			cout << n-3 << " " << 1 << endl;
			cout << 0 << " " << 2 << endl;
			for (int i = 3; i < n / 2; i++) {
				cout << i << " " << (i ^ (n - 1)) << endl;
			}
		} else {
			// pair k with n-1, complement of k with 0
			cout << k << " " << n-1 << endl;
			cout << (k ^ (n-1)) << " " << 0 << endl;
			for (int i = 1; i < n / 2; i++) {
				if (i == k || i == (k ^ (n - 1))) continue;
				cout << i << " " << (i ^ (n - 1)) << endl;
			}
		}
	}
}
