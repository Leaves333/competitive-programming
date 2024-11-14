#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;

		vector<ll> psum(n + 1);
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			psum[i + 1] = psum[i] + x;
		}

		while (q--) {
			ll l, r;
			cin >> l >> r;
			l--;

			ll left_arr = l + ((l % n == 0) ? 0 : (n - (l % n)));
			ll right_arr = r - (r % n);

			if (left_arr > right_arr) {
				ll cyclic_shifts = l / n;
				ll left_index = l % n;
				ll right_index = r % n;

				ll split_index = n - cyclic_shifts;
				ll ans = 0;
				if (right_index < split_index) {
					ans += psum[right_index + cyclic_shifts] - psum[left_index + cyclic_shifts];
				} else if (left_index >= split_index) {
					ans += psum[right_index + cyclic_shifts - n] - psum[left_index + cyclic_shifts - n];
				} else {
					ans += psum[n] - psum[left_index + cyclic_shifts];
					ans += psum[right_index + cyclic_shifts - n] - psum[0];
				}
				cout << ans << endl;
				continue;
			}

			// find the number of whole segments...
			ll ans = psum[n] * ((right_arr - left_arr) / n);

			// then calculate the segments with cyclic shift
			// 1: 1 2 3 4 5
			// 2: 2 3 4 5 1
			// 3: 3 4 5 1 2
			// ...
			
			// do left side
			if (l % n != 0) {
				ll cyclic_shifts = l / n; // 1
				ll nums = left_arr - l; // 4
				
				ll tmp = ans;
				ll nums_to_add = min(nums, cyclic_shifts); // min(4, 1) = 1
				ans += psum[cyclic_shifts] - psum[cyclic_shifts - nums_to_add]; // psum[1] - psum[0]
				nums -= nums_to_add;

				ans += psum[n] - psum[n - nums];
			}

			// do right side
			if (r % n != 0) {
				ll cyclic_shifts = r / n;
				ll nums = r - right_arr; // 2

				ll tmp = ans;
				ll nums_to_add = min(nums, n - cyclic_shifts); // min(2, 4) = 2
				ans += psum[cyclic_shifts + nums_to_add] - psum[cyclic_shifts];
				nums -= nums_to_add;

				ans += psum[nums];
			}

			cout << ans << endl;
		}
	}
}
