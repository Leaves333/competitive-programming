#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--) {

		int n; cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			b[i]--;
		}

		vector<ll> prefix_sum(n + 1);
		for (int i = 0; i < n; i++) {
			prefix_sum[i + 1] = prefix_sum[i] + a[i];
		}

		// calculate shortest path to each problem
		// then sum = shortest path - prefix sum
		// q stores pairs of (dist, index)

		vector<ll> shortest_dist(n, LLONG_MAX);
		priority_queue q = priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>();
		q.push(make_pair(0, 0));

		while (q.size() > 0) {

			auto t = q.top();
			q.pop();
			ll distance = t.first;
			ll index = t.second;

			if (distance >= shortest_dist[index]) {
				continue;
			}
			shortest_dist[index] = distance;

			// do this problem
			if (index > 0) {
				q.push(make_pair(distance, index - 1));
			}

			// skip this problem
			q.push(make_pair(distance + a[index], b[index]));

		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			if (shortest_dist[i] != LLONG_MAX) {
				ans = max(ans, prefix_sum[i + 1] - shortest_dist[i]);
			}
		}
		cout << ans << endl;
		
	}
}
