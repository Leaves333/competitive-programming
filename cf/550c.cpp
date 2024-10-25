#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	unordered_map<string, int> dp;
	for (int i = 0; i < 1000; i += 8) {
		dp[to_string(i)] = 0;
	}

	for (char c : str) {
		for (auto [key, value] : dp) {
			if (c == key[value]) {
				dp[key]++;
			}
			if (dp[key] >= key.length()) {
				cout << "YES" << endl;
				cout << key << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}
