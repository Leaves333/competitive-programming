#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    int source, dest, weight;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<edge>> edges(n + 1);
    for (int i = 0; i < n - 1 + m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({u, v, w});
        edges[v].push_back({v, u, w});
    }

    vvll ans(k+1, vll(k+1));
    for (int i = 1; i <= k; i++) {
        vll dist(n+1, LLONG_MAX);
        dist[i] = 0;

        // dist, index
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            ll cur_dist = pq.top().first;
            ll cur_idx = pq.top().second;
            pq.pop();
            // cout << "dijkstra at idx=" << cur_idx << ", dist=" << cur_dist << endl;

            if (cur_dist > dist[cur_idx]) {
                continue;
            }

            for (edge e : edges[cur_idx]) {
                ll new_dist = cur_dist + e.weight;
                if (new_dist < dist[e.dest]) {
                    dist[e.dest] = new_dist;
                    pq.push({new_dist, e.dest});
                }
            }
        }

        for (int j = 1; j <= k; j++) {
            ans[i][j] = dist[j];
        }

    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
