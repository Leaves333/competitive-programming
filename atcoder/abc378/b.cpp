#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> q(n);
	vector<int> r(n);
	for (int i = 0; i < n; i++) {
		cin >> q[i] >> r[i];
	}

	int queries; cin >> queries;
	for (int i = 0; i < queries; i++) {
		int t, d;
		cin >> t >> d;
		t--;

		int remainder = d % q[t];
		int time_to_wait = 0;
		if (remainder <= r[t]) {
			time_to_wait = r[t] - remainder;
		} else {
			time_to_wait = r[t] + q[t] - remainder;
		}
		cout << d + time_to_wait << endl;
	}
}
