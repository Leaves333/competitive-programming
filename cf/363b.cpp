#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	long long prefix_sum[n + 1];
	memset(prefix_sum, 0, sizeof(prefix_sum));

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		prefix_sum[i + 1] = prefix_sum[i] + x;
	}
	
	long long min_amount_to_remove = LLONG_MAX;
	int ans = -1;
	for (int i = k; i < n + 1; i++) {
		long long amount_to_remove = prefix_sum[i] - prefix_sum[i - k];
		if (amount_to_remove < min_amount_to_remove) {
			min_amount_to_remove = amount_to_remove;
			ans = i - k + 1;
		}
	}
	cout << ans << endl;

}
