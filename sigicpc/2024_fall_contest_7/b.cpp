#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> remainders(n - 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> remainders[i];
		}

		vector<int> ans(n);
		ans[0] = 501;
		for (int i = 1; i < n; i++) {
			ans[i] = ans[i - 1] + remainders[i - 1];
		}

		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
}
