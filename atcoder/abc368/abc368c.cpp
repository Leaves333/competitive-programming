#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long ans = 0;
	long long t = 1;
	for (int x : arr) {
		while (x > 0) {
			if (t % 3 == 0 && x >= 5) {
				int cycles = x / 5;
				ans += 3 * cycles;
				x -= cycles * 5;
			}
			else if (t % 3 == 0) {
				ans++;
				t++;
				x -= 3;
			}
			else {
				ans++;
				t++;
				x--;
			}
		}
	}

	cout << ans << endl;

}
