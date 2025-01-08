#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

struct edge {
    ll dest;
    ll weight;
};

int main() {

    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m, k;
    cin >> n >> m >> k;

    // read edges
    vector<vector<edge>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        edges[u].push_back(edge{v, x});
        edges[v].push_back(edge{u, x});
    }

    // read trains
    int ans = 0;
    vll dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    set<int> train_vertices;
    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        if (!train_vertices.count(s)) {
            dist[s] = y;
            train_vertices.insert(s);
        } else {
            ans++; // you remove one train either way
            dist[s] = min(dist[s], (ll)y);
        }
    }

    // djikstra's to find current shortest paths
    set<pair<ll, ll>> q; // priority queue storing {dist, vertex}
    q.insert(make_pair(0, 1));
    for (auto s : train_vertices) {
        q.insert(make_pair(dist[s], s));
    }

    while (q.size() > 0) {

        ll cur_dist = q.begin()->first;
        ll cur_vertex = q.begin()->second;
        q.erase(q.begin());

        for (edge e : edges[cur_vertex]) {

            ll new_dist = cur_dist + e.weight;
            if (new_dist > dist[e.dest])
                continue;

            if (train_vertices.count(e.dest)) {
                train_vertices.erase(e.dest);
                ans++;
            }

            q.erase(make_pair(dist[e.dest], e.dest));
            dist[e.dest] = new_dist;
            q.insert(make_pair(new_dist, e.dest));

        }
    }

    /*cout << ans << endl;*/
    cout << k - train_vertices.size() << endl;

}
