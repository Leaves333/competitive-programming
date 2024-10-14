#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long psum[n + 1];
	psum[0] = 0;
	for (int i = 0; i < n; i++) {
		psum[i + 1] = psum[i] + arr[i];
	}

	int ans = 0;
	int left = 0, right = 1;
	set<long long> s;
	s.insert(0);
	while (right < n + 1) {
		if (s.count(psum[right] - psum[left]) > 0) {
			ans++;
			left = right - 1;
			s.clear();
			s.insert(0);
		}
		s.insert(psum[right] - psum[left]);
		right++;
	}

	cout << ans << endl;
}
