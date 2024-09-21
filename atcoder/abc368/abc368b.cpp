#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int ans = 0;
	while (arr[n - 2] != 0) {
		ans++;
		arr[n - 1]--;
		arr[n - 2]--;
		sort(arr, arr + n);
	}

	cout << ans << endl;

}
