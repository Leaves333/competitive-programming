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
		vector<vll> psum(3, vll(n + 1));
		for (int j = 0; j < 3; j++) {
			for (int i = 1; i <= n; i++) {
				int x; cin >> x;
				psum[j][i] = psum[j][i - 1] + x;
			}
		}

		// try each permutation
		ll total = 1 + ((psum[0][n] - 1) / 3); // ceiling divison
		int permutations[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
		bool found = false;
		for (auto perm : permutations) {

			vector<pii> ans(3);
			int l = 1, r = 1;
			// test first person
			while (psum[perm[0]][r] - psum[perm[0]][l - 1] < total && r <= n) {
				r++;
			}
			ans[perm[0]] = make_pair(l, r);
			l = r + 1;

			// test second person
			while (psum[perm[1]][r] - psum[perm[1]][l - 1] < total && r <= n) {
				r++;
			}
			if (r > n) { continue; } // not valid
			ans[perm[1]] = make_pair(l, r);
			l = r + 1;

			if (psum[perm[2]][n] - psum[perm[2]][l - 1] < total) {
				continue; // not valid
			}
			ans[perm[2]] = make_pair(l, n);

			for (auto p : ans) {
				cout << p.first << " " << p.second << " ";
			}
			cout << endl;
			found = true;
			break;

		}

		if (!found) {
			cout << -1 << endl;
		}

	}
}
