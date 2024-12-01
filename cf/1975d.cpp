#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

void dfs(int cur, int parent, const vector<vi>& edges, vi& depth) {
	for (int dest : edges[cur]) {
		if (dest == parent) {
			continue;
		}
		depth[dest] = depth[cur] + 1;
		dfs(dest, cur, edges, depth);
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a, b; cin >> a >> b;
		vector<vi> edges(n + 1);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}

		vi dist_from_a(n + 1);
		vi dist_from_b(n + 1);
		dfs(a, 0, edges, dist_from_a);
		dfs(b, 0, edges, dist_from_b);

		int max_depth_a = 0, max_depth_b = 0;
		for (int i = 1; i < n + 1; i++) {
			max_depth_a = max(max_depth_a, dist_from_a[i]);
			max_depth_b = max(max_depth_b, dist_from_b[i]);
		}
		int dist_between_ab = dist_from_a[b];

		int go_to_a = 2 * (n - 1) - max_depth_a + dist_between_ab;
		int meet_halfway = 2 * (n - 1) - max_depth_b + dist_between_ab + (dist_between_ab % 2);
		cout << min(go_to_a, meet_halfway) << endl;
	}
}
