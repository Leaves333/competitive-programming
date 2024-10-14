#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	for (int i = 0; i < testcases; i++) {
		int x; cin >> x;
		int y = ceil(sqrt(x));

		if ((y - 1) * (y - 1) >= x) {
			cout << 2 * y - 4 << endl;
		} else if ((y - 1) * (y) >= x) {
			cout << 2 * y - 3 << endl;
		} else {
			cout << 2 * y - 2 << endl;
		}
	}

}
