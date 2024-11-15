#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {
		ll h, n;
		cin >> h >> n;

		vector<int> attack(n);
		vector<int> cooldown(n);
		for (int i = 0; i < n; i++) {
			cin >> attack[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> cooldown[i];
		}

		ll low = 1, high = h * 200000;
		while (low < high) { // min time such that boss is beaten
			ll mid = low + (high - low) / 2;

			ll total_damage = 0;
			for (int i = 0; i < n; i++) {
				total_damage += ((mid - 1) / cooldown[i] + 1) * attack[i];
				if (total_damage >= h) {
					break;
				}
			}
			
			if (total_damage >= h) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << low << endl;
	}
}
