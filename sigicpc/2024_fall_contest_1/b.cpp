#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for (int q = 0; q < t; q++) {

		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		vector<vector<int>> ans;
		for (int i = 0; i < n - 1; i++) {

			int min_index = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[min_index]) {
					min_index = j;
				}
			}
			int shift = min_index - i;
			if (shift == 0) {
				continue;
			}
			
			vector<int> v;
			v.push_back(i + 1);
			v.push_back(n);
			v.push_back(shift);
			ans.push_back(v);

			// copy the array
			int array_copy[n];
			for (int j = i; j < n; j++) {
				array_copy[j] = arr[j];
			}

			// cycle nums
			int arr_size = n - i;
			for (int j = 0; j < arr_size; j++) {
				arr[i + j] = array_copy[i + ((j + shift) % arr_size)];
			}

			/*for (auto x : arr) {*/
			/*	cout << x << " ";*/
			/*}*/
			/*cout << endl;*/
		}

		cout << ans.size() << endl;
		for (auto v : ans) {
			cout << v[0] << " " << v[1] << " " << v[2] << endl;
		}
	}
}
