#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n, q;
		cin >> n >> q;

		int points[n];
		for (int i = 0; i < n; i++) {
			cin >> points[i];
		}

		unordered_map<long long, int> segments_on_points;

		long long current_number_of_segments = n - 1;
		long long amount_to_add = n - 2;
		for (int i = 0; i < (n + 1) / 2; i++) {
			segments_on_points[current_number_of_segments] = 2;
			// edge case if its odd
			if (i == (n - 1) / 2 && n % 2 == 1) {
				segments_on_points[current_number_of_segments] = 1;
			}
			current_number_of_segments += amount_to_add;
			amount_to_add -= 2;
		}

		unordered_map<long long, int> segments_between_points;

		current_number_of_segments = n - 1;
		amount_to_add = n - 3;
		for (int i = 0; i < n / 2; i++) {
			int numbers_on_left = points[i + 1] - points[i] - 1;
			int numbers_on_right = points[n - i - 1] - points[n - i - 2] - 1;
			segments_between_points[current_number_of_segments] = numbers_on_left + numbers_on_right;

			if (i == (n / 2) - 1 && n % 2 == 0) {
				segments_between_points[current_number_of_segments] = numbers_on_left;
			}
			
			current_number_of_segments += amount_to_add;
			amount_to_add -= 2;
		}

		for (int i = 0; i < q; i++) {
			long long k; cin >> k;
			int ans = segments_on_points[k] + segments_between_points[k];
			cout << ans << " ";
		}
		cout << endl;

	}
}
