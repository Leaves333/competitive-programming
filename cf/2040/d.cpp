#pragma GCC optimize("O3")

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

	set<int> composite;
	composite.insert(1);
	for (int i = 2; i <= 200000; i++) {
		bool prime = true;
		for (int k = 2; k <= ceil(sqrt(i)); k++) {
			if (i % k == 0) {
				prime = false;
				break;
			}
		}
		if (!prime) composite.insert(i);
	}
	composite.erase(2);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<vi> edges(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		int max_edges_idx = 1;
		for (int i = 2; i <= n; i++) {
			if (edges[i].size() > edges[max_edges_idx].size()) {
				max_edges_idx = i;
			}
		}

		vi arr(n + 1);
		arr[max_edges_idx] = 1;
		bool used[400001];
		memset(used, false, sizeof(used));
		used[1] = true;
		stack<int> s;
		s.push(max_edges_idx);
		while (s.size() > 0) {
			int top = s.top();
			s.pop();

			int value = arr[top];
			auto difference = composite.begin();
			for (auto dest : edges[top]) {
				if (arr[dest] != 0) continue;
				while (used[value + *difference]) {
					difference++;
				}
				arr[dest] = value + *difference;
				used[value + *difference] = true;
				s.push(dest);
				difference++;
			}
		}

		for (int i = 1; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

	}
}
