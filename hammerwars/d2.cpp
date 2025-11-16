#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

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
    ll source, dest, weight;
};

set<int> nodes_set;
map<int, int> idx_map;
vector<vector<edge>> compressed_tree; // these indices are in terms of idx_map

void compress_dfs(int x, int parent, int last_important,
                  const vector<vector<edge>> &edges, ll cur_dist) {

    if (nodes_set.count(x)) {
        if (last_important == -1) {
            last_important = idx_map[x];
        } else {
            int cur_important = idx_map[x];
            compressed_tree[cur_important].push_back(
                {cur_important, last_important, cur_dist});
            compressed_tree[last_important].push_back(
                {last_important, cur_important, cur_dist});

            cur_dist = 0;
            last_important = idx_map[x];
        }
    }

    for (edge e : edges[x]) {
        if (e.dest != parent) {
            compress_dfs(e.dest, x, last_important, edges, cur_dist + e.weight);
        }
    }
}

void dfs(int x, int parent, const vector<vector<edge>> &edges, vll &dist) {
    for (edge e : edges[x]) {
        if (e.dest != parent) {
            dist[e.dest] = dist[x] + e.weight;
            dfs(e.dest, x, edges, dist);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    nodes_set.clear();
    for (int i = 1; i <= k; i++) {
        nodes_set.insert(i);
    }

    vector<vector<edge>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({u, v, w});
        tree[v].push_back({v, u, w});
    }

    vector<edge> shortcuts(m);
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        shortcuts[i] = {u, v, w};
        nodes_set.insert(u);
        nodes_set.insert(v);
    }

    vi nodes_of_interest(nodes_set.begin(), nodes_set.end());
    int sz = nodes_of_interest.size();

    idx_map.clear();
    for (int i = 0; i < sz; i++) {
        idx_map[nodes_of_interest[i]] = i;
    }

    compressed_tree.resize(sz);
    compress_dfs(nodes_of_interest[0], 0, -1, tree, 0);

    vvll dist(sz, vll(sz, 1e18));
    for (int i = 0; i < sz; i++) {
        dist[i][i] = 0;
        dfs(i, -1, compressed_tree, dist[i]);
    }

    for (edge e : shortcuts) {
        int i = idx_map[e.source];
        int j = idx_map[e.dest];
        dist[i][j] = min(dist[i][j], e.weight);
        dist[j][i] = min(dist[j][i], e.weight);
    }

    for (int k = 0; k < sz; ++k) {
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            int x = idx_map[i];
            int y = idx_map[j];
            cout << dist[x][y] << " ";
        }
        cout << endl;
    }

}
