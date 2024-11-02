#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns the maximum score starting from a given location
ll dfs(int loc, int time_left, ll collected_score, vector<int>& permutation, vector<int>& arr, unordered_set<int>& visited) {
	if (time_left == 0) {
		return 0;
	}
	visited.insert(loc);
	ll res = collected_score + ((ll) arr[loc] * (time_left));
	if (visited.count(permutation[loc]) == 0) {
		res = max(res, dfs(permutation[loc], time_left - 1, collected_score + arr[loc], permutation, arr, visited));
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {

		int n, k, b, s;
		cin >> n >> k >> b >> s;

		vector<int> permutation(n);
		vector<int> arr(n);

		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			permutation[i] = x - 1;
		}

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		unordered_set<int> visited;
		ll score_bodya = dfs(b - 1, k, 0, permutation, arr, visited);
		visited.clear();
		ll score_sasha = dfs(s - 1, k, 0, permutation, arr, visited);

		if (score_bodya == score_sasha) {
			cout << "Draw" << endl;
		} else if (score_bodya > score_sasha) {
			cout << "Bodya" << endl;
		} else {
			cout << "Sasha" << endl;
		}

	}
}
