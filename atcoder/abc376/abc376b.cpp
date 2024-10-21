#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	int left = 0, right = 1;
	int ans = 0;
	for (int i = 0; i < q; i++) {
		char dir; int pos;
		cin >> dir >> pos;
		pos--;

		if (dir == 'L') {

			int new_left = left;
			int moves = 0;
			bool good_direction = true;
			while (new_left != pos) {
				new_left++;
				new_left %= n;
				moves++;
				if (new_left == right) {
					good_direction = false;
					break;
				}
			}

			if (good_direction) {
				ans += moves;
				left = new_left;
				continue;
			}

			new_left = left;
			moves = 0;
			while (new_left != pos) {
				new_left--;
				if (new_left < 0) { new_left += n; }
				moves++;
			}

			left = new_left;
			ans += moves;

		} else {

			int new_right = right;
			int moves = 0;
			bool good_direction = true;
			while (new_right != pos) {
				new_right++;
				new_right %= n;
				moves++;
				if (new_right == left) {
					good_direction = false;
					break;
				}
			}

			if (good_direction) {
				ans += moves;
				right = new_right;
				continue;
			}

			new_right = right;
			moves = 0;
			while (new_right != pos) {
				new_right--;
				if (new_right < 0) { new_right += n; }
				moves++;
			}

			right = new_right;
			ans += moves;

		}

	}

	cout << ans << endl;

}
