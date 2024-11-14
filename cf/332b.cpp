#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;

	ll psum[n + 1];
	memset(psum, 0, sizeof(psum));
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		psum[i + 1] = psum[i] + x;
	}

	const int num_segments = n - k + 1;
	ll segments[num_segments];
	for (int i = 0; i < num_segments; i++) {
		segments[i] = psum[i + k] - psum[i];
	}

	const int r = num_segments - k;
	int max_segment_to_right[r]; // value, index
	max_segment_to_right[r - 1] = num_segments - 1;
	for (int i = r - 2; i >= 0; i--) {
		if (segments[i + k] >= segments[max_segment_to_right[i + 1]]) {
			max_segment_to_right[i] = i + k;
		} else {
			max_segment_to_right[i] = max_segment_to_right[i + 1];
		}
	}

	ll max_val = 0;
	pair<int, int> ans;
	for (int i = 0; i < r; i++) {
		ll sum = segments[i] + segments[max_segment_to_right[i]];
		if (sum > max_val) {
			max_val = sum;
			ans = make_pair(i, max_segment_to_right[i]);
		}
	}

	cout << ans.first + 1 << " " << ans.second + 1 << endl;

}
