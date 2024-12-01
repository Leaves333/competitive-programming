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
		int n; cin >> n;
		vll psum(n + 1);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			psum[i + 1] = psum[i] + x;
		}

		int q; cin >> q;
		while (q--) {
			int l, u; cin >> l >> u;

			// binary search
			int low = l, high = n;
			while (low < high) {
				int mid = low + (high - low) / 2;
				ll num_tracks = psum[mid] - psum[l - 1];
				ll cur_value = num_tracks * (u + u - num_tracks + 1);
				num_tracks = psum[mid + 1] - psum[l - 1];
				ll next_value = num_tracks * (u + u - num_tracks + 1);
				if (cur_value >= next_value) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			cout << low << " ";
		}
		cout << endl;
	}
}
