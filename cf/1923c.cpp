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
		int n, q;
		cin >> n >> q;
		vll nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		vll psum(n + 1);
		vll number_of_ones(n + 1);
		for (int i = 1; i < n + 1; i++) {
			psum[i] = psum[i - 1] + nums[i - 1];
			if (nums[i - 1] == 1) {
				number_of_ones[i] = number_of_ones[i - 1] + 1;
			} else {
				number_of_ones[i] = number_of_ones[i - 1];
			}
		}

		while (q--) {
			ll l, r;
			cin >> l >> r;

			ll ones = number_of_ones[r] - number_of_ones[l - 1];
			ll potential = psum[r] - psum[l - 1] - (r - l + 1);

			/*cout << ones << " | " << potential << endl;*/
			if (l != r && potential >= ones) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}
