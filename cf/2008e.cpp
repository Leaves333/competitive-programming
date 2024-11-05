#include <bits/stdc++.h>
using namespace std;

int main() {

	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		string str; cin >> str;
		
		int pref_even[n + 1][26];
		int suff_even[n + 1][26];
		int pref_odd[n + 1][26];
		int suff_odd[n + 1][26];

		memset(pref_even, 0, sizeof(pref_even));
		memset(pref_odd, 0, sizeof(pref_odd));
		memset(suff_even, 0, sizeof(suff_even));
		memset(suff_odd, 0, sizeof(suff_odd));

		// construct prefix sum
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) {
				pref_even[i + 1][j] = pref_even[i][j];
				pref_odd[i + 1][j] = pref_odd[i][j];
			}
			if (i % 2 == 0) {
				pref_even[i + 1][str[i] - 'a']++;
			} else {
				pref_odd[i + 1][str[i] - 'a']++;
			}
		}

		// construct suffix sum
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				suff_even[i][j] = suff_even[i + 1][j];
				suff_odd[i][j] = suff_odd[i + 1][j];
			}
			if (i % 2 == 0) {
				suff_even[i][str[i] - 'a']++;
			} else {
				suff_odd[i][str[i] - 'a']++;
			}
		}

		// if n is even...
		if (n % 2 == 0) {
			int largest_even = 0;
			int largest_odd = 0;
			for (int i = 0; i < 26; i++) {
				largest_even = max(largest_even, pref_even[n][i]);
				largest_odd = max(largest_odd, pref_odd[n][i]);
			}
			cout << n - largest_even - largest_odd << endl;
			continue;
		}

		// if n is odd...
		// brute force removing each char, then do the calculation
		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {

			int even_count[26];
			int odd_count[26];
			for (int k = 0; k < 26; k++) {
				even_count[k] = pref_even[i][k] + suff_odd[i + 1][k];
				odd_count[k] = pref_odd[i][k] + suff_even[i + 1][k];
			}

			int largest_even = 0;
			int largest_odd = 0;
			for (int k = 0; k < 26; k++) {
				largest_even = max(largest_even, even_count[k]);
				largest_odd = max(largest_odd, odd_count[k]);
			}

			ans = min(ans, n - largest_even - largest_odd);

		}
		cout << ans << endl;

	}

}
