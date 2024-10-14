#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n, k;
		cin >> n >> k;

		int start = 0, end = n;
		if (n > k) {
			start = n - k;
		}

		int num_odds = 0;
		if (end % 2 == 0) {
			num_odds = (end - start) / 2;
		} else {
			num_odds = (end - start + 1) / 2;
		}

		if (num_odds % 2 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

}
