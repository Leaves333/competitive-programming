#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<char, int> m;
	string s;
	cin >> s;
	for (char c : s) {
		m[c] = 1;
	}

	if (m['A'] == 1 && m['B'] == 1 && m['C'] == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
