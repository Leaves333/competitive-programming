#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << endl;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[j] << " ";
		}
		cout << endl;

		int *new_arr = new int[n];
		for (int j = 0; j < n; j++) {
			new_arr[j] = arr[arr[j] - 1];
		}
		delete[] arr;
		arr = new_arr;
	}
}
