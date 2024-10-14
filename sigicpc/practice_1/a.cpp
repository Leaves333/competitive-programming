#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {
		int n; cin >> n;
		int max_odd = 0;
		int max_even = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (i % 2 == 0) {
				max_odd = max(x, max_odd);
			} else {
				max_even = max(x, max_even);
			}
		}
		cout << max(max_odd + (n + 1) / 2, max_even + n / 2) << endl;
	}
}
