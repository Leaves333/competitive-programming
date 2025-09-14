#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

void dfs(int x, int depth, vi &dist, vi &parent, const vvi &edges) {
    dist[x] = depth;
    for (auto dest : edges[x]) {
        if (dist[dest] != -1) 
            continue;
        parent[dest] = x;
        dfs(dest, depth + 1, dist, parent, edges);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vvi edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        // THE PLAN:
        // dfs to find diameter
        // walk along diameter to find a, b, c
        // where a, b on the diameter, a -> b -> c, c not on diameter

        // dfs once...
        vi dist(n + 1, -1);
        vi parent(n + 1, -1);
        dfs(1, 0, dist, parent, edges);
        int a = 1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] > dist[a])
                a = i;
        }

        // dfs again...
        dist.assign(n + 1, -1);
        parent.assign(n + 1, -1);
        dfs(a, 0, dist, parent, edges);

        int b = 1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] > dist[b])
                b = i;
        }

        // reconstruct diameter
        vi path; int cur = b;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        // walk along diameter and find answer
        bool found = false;
        for (int i = 1; i < path.size() - 1; i++) {
            int cur = path[i], prev = path[i - 1], next = path[i + 1];
            for (auto dest : edges[cur]) {
                if (dest == prev || dest == next)
                    continue;
                found = true;
                cout << prev << " " << cur << " " << dest << endl;
                break;
            }
            if (found) {
                break;
            }
        }

        if (!found)
            cout << -1 << endl;

    }
}
