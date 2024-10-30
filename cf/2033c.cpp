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

		for (int i = 1; i < n / 2; i++) {
			if (arr[i] == arr[i - 1] || arr[n - i - 1] == arr[n - i]) {
				int tmp = arr[i];
				arr[i] = arr[n - i - 1];
				arr[n - i - 1] = tmp;
			}
		}

		int ans = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] == arr[i - 1]) {
				ans++;
			}
		}
		cout << ans << endl;
		
	}
}
