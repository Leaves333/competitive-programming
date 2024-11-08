#include <bits/stdc++.h>
using namespace std;

int main() {

	int t; cin >> t;
	while (t--) {

		int n; string s;
		cin >> n >> s;

		// all odd strings are bad
		if (n % 2 == 1) {
			cout << -1 << endl;
			continue;
		}

		// actually solve problem
		// observations:
		// for all good strings, number of 1s = number of 0s

	}

}
