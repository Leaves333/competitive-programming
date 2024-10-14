#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	map<int, int> freq;

	for (int i = 0; i < 10 * n; i++) {
		for (int j = 0; j < 5; j++) {
			int x; cin >> x;
			if (freq.count(x) == 0) {
				freq[x] = 0;
			}
			freq[x]++;
		}
	}

	bool found = false;
	for (auto it = freq.begin(); it != freq.end(); it++) {
		if (it->second > n * 2) {
			found = true;
			cout << it->first << " ";
		}
	}

	if (!found) {
		cout << -1 << endl;
	}
	cout << endl;
	
}
