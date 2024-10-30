#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n, k;
		cin >> n >> k;

		// max f such that left < right
		long long low = 0, high = n;
		while (low < high) {
			long long mid = low + (high - low + 1) / 2;

			long long left_side = ((k + k + mid - 1) * mid) / 2;
			long long right_side = ((k + mid + k + n - 1) * (n - mid)) / 2;

			if (left_side > right_side) {
				high = mid - 1;
			} else {
				low = mid;
			}
		}

		long long left = ((k + k + low - 1) * low) / 2;
		long long right = ((k + low + k + n - 1) * (n - low)) / 2;
		long long diff = abs(left - right);

		/*cout << low << ": " << left << " | " << right << endl;*/

		low += 1;
		left = ((k + k + low - 1) * low) / 2;
		right = ((k + low + k + n - 1) * (n - low)) / 2;
		/*cout << low << ": " << left << " | " << right << endl;*/
		cout << min(abs(left - right), diff) << endl;

		/*cout << endl;*/

	}
}
