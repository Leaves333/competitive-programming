#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll sum = 0;

		set<ll> seen;
		seen.insert(0);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			sum += x;
			if (seen.count(sum) > 0) {
				ans++;
				seen.clear();
				sum = 0;
			}
			seen.insert(sum);
		}
		
		cout << ans << endl;

	}
}
