#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {

		// grab input
		int n; cin >> n;
		long long arr[n];
		int max_idx = 0;
		long long total_wealth = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			total_wealth += arr[i];
			if (arr[i] > arr[max_idx]) {
				max_idx = i;
			}
		}

		long long low = 0, high = 1000000000000;
		while (low < high) {

			long long mid = low + (high - low) / 2;

			arr[max_idx] += mid;
			double half_of_average_wealth = ((double) total_wealth + mid) / (n * 2);
			int number_of_unhappy_people = 0;
			for (long long x : arr) {
				if (x < half_of_average_wealth) {
					number_of_unhappy_people++;
				}
			}

			arr[max_idx] -= mid;

			if (number_of_unhappy_people > ((double) n / 2)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}

		if (low == 1000000000000) {
			cout << -1 << endl;
		} else {
			cout << low << endl;
		}

	}

}
