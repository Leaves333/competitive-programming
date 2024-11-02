#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> ribbons(n);
	for (int i = 0; i < n; i++) {
		cin >> ribbons[i];
	}

	map<int, int> color_frequencies;
	map<int, int> count_frequencies;
	int ans = 0;
	count_frequencies[0] = 1;

	for (int i = 0; i < n; i++) {

		color_frequencies[ribbons[i]]++;
		count_frequencies[color_frequencies[ribbons[i]]]++;
		count_frequencies[color_frequencies[ribbons[i]] - 1]--;
		if (count_frequencies[color_frequencies[ribbons[i]] - 1] <= 0) {
			count_frequencies.erase(color_frequencies[ribbons[i]] - 1);
		}

		if (color_frequencies.size() == 1) {
			ans = i + 1;
		} else if (count_frequencies.size() == 1 && count_frequencies.begin()->first == 1) {
			ans = i + 1;
		} else if (count_frequencies.size() == 2) {
			auto it = count_frequencies.begin();
			int key_one = it->first;
			it++;
			int key_two = it->first;

			int small_key = min(key_one, key_two);
			int big_key = max(key_one, key_two);
			if (small_key == 1 && count_frequencies[small_key] == 1
				|| small_key + 1 == big_key && count_frequencies[big_key] == 1) {
				ans = i + 1;
			}

		}
	}

	cout << ans << endl;
}
