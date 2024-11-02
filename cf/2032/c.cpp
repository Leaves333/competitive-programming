#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		vector<int> pair_sums(n - 1);
		for (int i = 0; i < n - 1; i++) {
			pair_sums[i] = arr[i] + arr[i + 1];
		}

		// check min operations?
		int ans = INT_MAX;
		int left = 0, right = 1;
		while (right < n) {
			while (pair_sums[left] <= arr[right]) {
				left++;
			}
			int operations = left + n - right - 1;
			ans = min(ans, operations);
			right++;
		}

		cout << ans << endl;

	}
}
