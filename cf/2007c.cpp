#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	while (b > 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		const int mod = gcd(a, b);
		set<int> nums;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			nums.insert(x % mod);
		}

		if (nums.size() == 1) {
			cout << 0 << endl;
			continue;
		}

		int ans = INT_MAX;
		auto first = nums.begin();
		auto second = nums.begin();
		second++;
		while (second != nums.end()) {
			int diff = (*first + mod - *second) % mod;
			ans = min(ans, diff);
			first++;
			second++;
		}

		// check last index
		int diff = (*first + mod - *nums.begin()) % mod;
		ans = min(ans, diff);
		cout << ans << endl;
	}
}
