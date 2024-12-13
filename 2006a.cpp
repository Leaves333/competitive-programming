#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vi degree(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			degree[a]++;
			degree[b]++;
		}

		string s; cin >> s;
		int middle_nodes = 0, leaves_with_0 = 0, leaves_with_1 = 0, leaves_empty = 0;
		for (int i = 1; i < n; i++) {
			if (degree[i + 1] == 1) {
				if (s[i] == '0') leaves_with_0++;
				else if (s[i] == '1') leaves_with_1++;
				else leaves_empty++;
			} else {
				middle_nodes += (s[i] == '?');
			}
		}

		int score = 0;
		if (s[0] == '0') {
			score += leaves_with_1;
			score += leaves_empty / 2 + (leaves_empty % 2 != 0);
		} else if (s[0] == '1') {
			score += leaves_with_0;
			score += leaves_empty / 2 + (leaves_empty % 2 != 0);
		} else {
			if (leaves_with_0 == leaves_with_1) {
				if (middle_nodes % 2 == 0) {
					score += max(leaves_with_0, leaves_with_1);
					score += leaves_empty / 2;
				} else {
					score += max(leaves_with_0, leaves_with_1);
					score += (leaves_empty + 1) / 2;
				}
			} else {
				score += max(leaves_with_0, leaves_with_1);
				score += leaves_empty / 2;
			}
		}

		cout << score << endl;
	}
}
