#include <bits/stdc++.h>
using namespace std;

const int MAX_BITS = 24;

bool check(int a, vector<int>& arr) {
	int left = 0, right = 0;
	vector<int> count(MAX_BITS, 0);
	while (right < a) {
		int x = arr[right];
		for (int i = 0; i < MAX_BITS; i++) {
			if (x & 1 << i) {
				count[i]++;
			}
		}
		right++;
	}

	int mask = 0;
	for (int i = 0; i < MAX_BITS; i++) {
		if (count[i] > 0) {
			mask += 1 << i;
		}
	}

	while (right < arr.size()) {
		int x = arr[right];
		for (int i = 0; i < MAX_BITS; i++) {
			if (x & 1 << i) {
				count[i]++;
			}
		}
		right++;

		x = arr[left];
		for (int i = 0; i < MAX_BITS; i++) {
			if (x & 1 << i) {
				count[i]--;
			}
		}
		left++;
		
		int cur_mask = 0;
		for (int i = 0; i < MAX_BITS; i++) {
			if (count[i] > 0) {
				cur_mask += 1 << i;
			}
		}
		if (cur_mask != mask) {
			return false;
		}
	}

	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		// binary search over ans
		int low = 1, high = n;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (check(mid, arr)) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		cout << low << endl;
	}
}
