#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		// with given median...
		// want to create same number of arrays on the left as arrays on the right???
		// bc n is always odd...
		// case 1: median subarray has len 1, or len 3
		
		// edge case: n=1
		if (n == 1) {
			cout << "1\n1" << endl;
			continue;
		}

		int median = -1, left = -1, right = -1;
		if (k % 2 == 0) {
			if (k == 1 || k == n) {
				cout << "-1" << endl;
				continue;
			}
			median = k;
			left = 1;
			right = k + 1;
			cout << "3\n" << left << " " << median << " " << right << endl;
		} else {
			if (k <= 2 || k >= n - 1) {
				cout << "-1" << endl;
				continue;
			}
			median = k - 1;
			left = 1;
			right = k + 2;
			cout << "3\n" << left << " " << median << " " << right << endl;
		}
	}
}
