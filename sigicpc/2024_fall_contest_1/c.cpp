#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {

		int n, m, k;
		cin >> n >> m >> k;
		string field[n];
		for (int i = 0; i < n; i++) {
			cin >> field[i];
		}

		bool can_be_tick[n][m];
		memset(can_be_tick, false, sizeof(can_be_tick));

		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
			
				if (field[row][col] != '*') {
					continue;
				}

				int d = 0;
				while (true) {
					if (row - d < 0) {
						break;
					}
					if (col - d < 0 || col + d >= m) {
						break;
					}
					if (field[row - d][col - d] != '*' || field[row - d][col + d] != '*') {
						break;
					}
					d++;
				}
				d--; // last valid size of d

				if (d < k) {
					continue; // too small to be a tick
				}

				for (int i = 0; i <= d; i++) {
					can_be_tick[row - i][col + i] = true;
					can_be_tick[row - i][col - i] = true;
				}

			}
		}

		bool good = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == '*' && can_be_tick[i][j] == false) {
					good = false;
				}
			}
		}
		
		if (!good) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
		
	}
}
