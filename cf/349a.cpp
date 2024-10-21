#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int twentyfives = 0, fifties = 0;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == 25) {
			twentyfives++;
		} else if (x == 50) {
			if (twentyfives == 0) {
				cout << "NO" << endl;
				return 0;
			}
			twentyfives--;
			fifties++;
		} else {
			if (fifties > 0 && twentyfives > 0) {
				fifties--;
				twentyfives--;
			} else if (twentyfives >= 3) {
				twentyfives -= 3;
			} else {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
}
