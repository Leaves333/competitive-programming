#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;

	int ans = 0;
	int last_candy = -10000;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x - last_candy >= c) {
			ans++;
			last_candy = x;
		}
	}

	cout << ans << endl;
}
