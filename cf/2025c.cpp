#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());
		int ans = 1;
		int unique_cards = 1;

		int left = 0, right = 0;
		while (right < n - 1) {
			right++;
			if (arr[right] == arr[right - 1] + 1) {
				unique_cards++;
			} else if (arr[right] != arr[right - 1]) {
				left = right;
				unique_cards = 1;
			}
			
			while (unique_cards > k) {
				left++;
				if (arr[left] != arr[left - 1]) {
					unique_cards--;
				}
			}

			ans = max(ans, right - left + 1);
		}

		cout << ans << endl;
	}
}
