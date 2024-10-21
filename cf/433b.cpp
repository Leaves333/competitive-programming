#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	vector<int> stones(n);
	long long psum[n + 1];
	memset(psum, 0, sizeof(psum));

	for (int i = 0; i < n; i++) {
		cin >> stones[i];
		psum[i + 1] = stones[i] + psum[i];
	}


	sort(stones.begin(), stones.end());
	long long psum_sorted[n + 1];
	memset(psum_sorted, 0, sizeof(psum_sorted));
	for (int i = 0; i < n; i++) {
		psum_sorted[i + 1] = psum_sorted[i] + stones[i];
	}

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			cout << psum[r] - psum[l - 1] << endl;
		} else {
			cout << psum_sorted[r] - psum_sorted[l - 1] << endl;
		}
	}

}
