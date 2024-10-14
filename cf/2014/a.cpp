#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n, k;
		cin >> n >> k;

		int gold = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x >= k) {
				gold += x;
			} else if (x == 0 && gold > 0) {
				gold--;
				ans++;
			}
		}

		cout << ans << endl;
	}

}
