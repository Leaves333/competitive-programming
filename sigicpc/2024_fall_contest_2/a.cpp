#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n, x;
		cin >> n >> x;
		if (x <= 2) {
			cout << 1 << endl;
		} else {
			int max_floor = 2;
			int ans = 1;
			while (max_floor < n) {
				max_floor += x;
				ans++;
			}
			cout << ans << endl;
		}
	}
}
