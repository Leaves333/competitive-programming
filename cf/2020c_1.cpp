#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		ll b, c, d;
		cin >> b >> c >> d;

		ll ans = 0;
		for (int i = 0; i < 61; i++) {
			ll mask = (ll) 1 << i;

			// bit needs to be one
			if (d & mask) {
				// b=0, c=0 -- make a=1
				// b=1, c=0 -- make a=1
				// b=0, c=1 -- impossible
				// b=1, c=1 -- make a=0

				if (!(c & mask)) {
					ans += mask;
				} else if (!(b & mask) && (c & mask)) {
					ans = -1;
					break;
				}
				
			// bit needs to be 0
			} else {
				// b=0, c=0 -- make a=0
				// b=1, c=0 -- impossible
				// b=0, c=1 -- make a=1
				// b=1, c=1 -- make a=1

				if (c & mask) {
					ans += mask;
				} else if ((b & mask) && !(c & mask)) {
					ans = -1;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
