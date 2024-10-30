#include <bits/stdc++.h>
using namespace std;

int main() {
	bool safe[8][8];
	memset(safe, true, sizeof(safe));

	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '#') {
				for (int k = 0; k < 8; k++) {
					safe[i][k] = false;
					safe[k][j] = false;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (safe[i][j]) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
