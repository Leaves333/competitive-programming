#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	long long ans = 0;
	int pos = 0;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		x--; // adjust offset

		if (pos <= x) {
			ans += x - pos;
		} else {
			ans += n - pos + x;
		}
		pos = x;
	}

	cout << ans << endl;
}
