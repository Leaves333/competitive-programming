#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;

		vector<int> numbers;
		int ans = 0;
		if (n % 2 == 1) {

			ans = n;

			int lowest_bit = -1;
			for (int i = 0; i < 20; i++) {
				if (n & (1 << i)) {
					lowest_bit = 1 << i;
					break;
				}
			}

			numbers.push_back(lowest_bit);
			numbers.push_back(lowest_bit + (lowest_bit == 1 ? 2 : 1));
			numbers.push_back(n - lowest_bit);
			numbers.push_back(n);

		} else {
			// check if n is a power of two
			if ((n & (n - 1)) == 0) {
				ans = n | (n - 1);
				numbers.push_back(1);
				numbers.push_back(3);
				numbers.push_back(n - 2);
				numbers.push_back(n - 1);
				numbers.push_back(n);
			} else {

				int largest_bit = -1;
				for (int i = 20; i >= 0; i--) {
					if (n & (1 << i)) {
						largest_bit = 1 << i;
						break;
					}
				}

				numbers.push_back(largest_bit);
				numbers.push_back(largest_bit + 1);
				numbers.push_back(largest_bit - 1);
				ans = n | (largest_bit - 1);
			}
		}

		set<int> numbers_used;
		for (int x : numbers) {
			numbers_used.insert(x);
		}

		cout << ans << endl;
		for (int i = 1; i <= n; i++) {
			if (numbers_used.count(i) == 0) {
				cout << i << " ";
			}
		}
		for (int x : numbers) {
			cout << x << " ";
		}
		cout << endl;
	}
}
