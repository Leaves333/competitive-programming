#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		const int mod = 2 * k;
		set<int> nums;
		int latest = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			latest = max(latest, x);
			nums.insert(x % mod);
		}

		auto cur = nums.begin();
		cur++;
		auto prev = nums.begin();
		int ans = -1;
		while (cur != nums.end()) {
			int start = *cur;
			int end = *prev;
			if (start + k > end + mod) {
				ans = ((latest / mod) * mod) + end;
				if (ans < latest) { ans += mod; }
			}
			cur++;
			prev++;
		}

		// check loop around
		int start = *nums.begin();
		int end = *prev;
		if (start + k > end) {
			ans = ((latest / mod) * mod) + end;
		}

		cout << ans << endl;
	}
}
