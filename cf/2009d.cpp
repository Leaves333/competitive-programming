#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		set<int> points_zero;
		set<int> points_one;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			if (y == 0) {
				points_zero.insert(x);
			} else {
				points_one.insert(x);
			}
		}

		long long ans = 0;
		for (int x : points_zero) {
			if (points_one.count(x + 1) && points_one.count(x - 1)) {
				ans++;
			}
			if (points_one.count(x)) {
				ans += points_one.size() - 1;
			}
		}

		for (int x : points_one) {
			if (points_zero.count(x + 1) && points_zero.count(x - 1)) {
				ans++;
			}
			if (points_zero.count(x)) {
				ans += points_zero.size() - 1;
			}
		}

		cout << ans << endl;

	}
}
