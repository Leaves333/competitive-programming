#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = -1, right = -1;
	unordered_map<int, int> seen;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			left = i;
			break;
		}
	}
	if (left == -1) {
		left = n - 1;
	}

	for (int i = left; i < n; i++) {
		if (seen.count(arr[i]) == 0) {
			seen[arr[i]] = 0;
		}
		seen[arr[i]] += 1;
		if (seen.size() >= k) {
			right = i;
			break;
		}
	}

	while (seen.size() >= k) {
		seen[arr[left]]--;
		if (seen[arr[left]] <= 0) {
			seen.erase(seen.find(arr[left]));
		}
		left++;
	}

	if (right == -1) {
		cout << "-1 -1" << endl;
	} else {
		cout << left << " " << right + 1 << endl;
	}
}
