#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, g, b;
	cin >> r >> g >> b;

	int max_mixed = min(r, min(g, b));
	int ans = 0;

	for (int i = 0; i < 3; i++) {
		if (max_mixed - i < 0) {
			continue;
		}

		int cur = 0;
		cur += max_mixed - i;
		cur += (r - (max_mixed - i)) / 3;
		cur += (g - (max_mixed - i)) / 3;
		cur += (b - (max_mixed - i)) / 3;

		ans = max(ans, cur);
	}

	cout << ans << endl;
}
