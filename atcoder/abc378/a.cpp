#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> count;
	for (int i = 0; i < 4; i++) {
		int x; cin >> x;
		count[x]++;
	}
	int ans = 0;
	for (auto p : count) {
		ans += p.second / 2;
	}
	cout << ans << endl;
}
