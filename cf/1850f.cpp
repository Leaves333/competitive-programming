#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, int> frogs;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			frogs[x]++;
		}

		vector<int> caught(n + 1);
		for (auto p : frogs) {
			for (int i = p.first; i <= n; i += p.first) {
				caught[i] += p.second;
			}
		}

		int ans = 0;
		for (int i = 0; i < caught.size(); i++) {
			ans = max(ans, caught[i]);
		}
		cout << ans << endl;
	}
}
