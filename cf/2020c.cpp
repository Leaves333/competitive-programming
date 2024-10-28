#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		ll b, c, d;
		cin >> b >> c >> d;

		// find a such that (a | b) - (a & c) = d.
		// a | b = d + (a & c)

		ll low = 0, high = (ll) 1 << 61;
		bool found = false;
		while (low < high) {
			ll a = low + (high - low) / 2;
			ll first = a | b;
			ll second = a & c;

			ll diff = first - second;
			cout << a << ": " << first << " - " << second << " = " << diff << endl;

			if (diff == d) {
				found = true;
				cout << a << endl;
				break;
			} else if (diff > d) {
				high = a - 1;
			} else {
				low = a + 1;
			}
		}

		if (!found) {
			cout << -1 << endl;
		}
	}
}
