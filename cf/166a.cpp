#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> teams;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		teams.push_back(make_pair(a, b));
	}

	struct
    {
        bool operator()(pair<int, int> a, pair<int, int> b) const { 
			if (a.first != b.first) {
				return a.first > b.first;
			} else {
				return a.second < b.second;
			}
		}
    }
    customSort;

	sort(teams.begin(), teams.end(), customSort);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		const auto& cur = teams[i];
		if (cur.first == teams[k - 1].first && cur.second == teams[k - 1].second) {
			ans++;
		}
	}

	cout << ans << endl;

}
