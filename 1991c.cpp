#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		vector<int> arr(n);
		set<int> parities;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			parities.insert(arr[i] % 2);
		}

		if (parities.size() == 2) {
			cout << -1 << endl;
			continue;
		}

		sort(arr.begin(), arr.end(), greater<int>());
		int k = 0;
		vector<int> ans;
		while (arr[0] > 0) {
			vector<int> new_arr(n);
			int x = (arr[0] + 1) / 2;
			ans.push_back(x);
			k++;
			for (int i = 0; i < arr.size(); i++) {
				new_arr[i] = abs(arr[i] - x);
			}
			sort(new_arr.begin(), new_arr.end(), greater<int>());
			arr = new_arr;
		}

		cout << k << endl;
		for (int x : ans) {
			cout << x << " ";
		}
		cout << endl;

	}
}
