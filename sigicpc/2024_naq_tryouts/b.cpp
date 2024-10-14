#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	double ans = 100000000;
	for (int i = 0; i < n; i++) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 < 0 && x2 < 0 || x1 > 0 && x2 > 0 || x1 == x2) {
			continue;
		}

		double slope = (y2 - y1) / (x2 - x1);
		double intersection = y2 - (slope * x2);
		if (intersection < 0) {
			continue;
		}
		ans = min(ans, intersection);
	}

	if (ans == 100000000) {
		cout << "-1.0" << endl;
	} else {
		cout << ans << endl;
	}
}
