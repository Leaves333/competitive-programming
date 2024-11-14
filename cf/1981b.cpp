#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int ans = n;
		for (int i = 0; i < 31; i++) {
			int bit = 1 << i;
			int x = n % bit;
			if (n >= bit && min(x + 1, bit - x) <= m) {
				ans |= bit;
			} else if (bit - x <= m) {
				ans |= bit;
			}
		}
		cout << ans << endl;
	}
}
