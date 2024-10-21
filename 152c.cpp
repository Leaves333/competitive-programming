#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_set<char> chars_at_index[m];
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			chars_at_index[j].insert(str[j]);
		}
	}

	const long long MOD = 1000000007;
	long long ans = 1;
	for (int i = 0; i < m; i++) {
		ans *= chars_at_index[i].size();
		ans %= MOD;
	}

	cout << ans << endl;

}
