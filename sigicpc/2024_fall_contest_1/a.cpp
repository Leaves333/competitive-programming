#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string s; cin >> s;
		int arr[3];
		arr[0] = 0; arr[1] = 0; arr[2] = 0;
		for (char c : s) {
			arr[c - 'A']++;
		} 
		if (arr[0] + arr[2] == arr[1]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
