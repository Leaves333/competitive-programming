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

struct DSU {

    vi parent, size;

    void init_dsu(int n) {
        parent = vi(n);
        size = vi(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<pii> f_edges;

        DSU g_dsu;
        g_dsu.init_dsu(n);

        for (int i = 0; i < a; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            f_edges.push_back({u, v});
        }

        for (int i = 0; i < b; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g_dsu.union_sets(u, v);
        }

        DSU f_dsu;
        f_dsu.init_dsu(n);
        int ans = 0;
        for (pii edge : f_edges) {
            int u = edge.first;
            int v = edge.second;

            // same component in g...
            // we should add this edge.
            if (g_dsu.find_set(u) == g_dsu.find_set(v)) {
                f_dsu.union_sets(u, v);
            } else {
                // not in the same component, need to get rid of this edge
                ans++;
            }
        }

        set<int> f_components;
        set<int> g_components;
        for (int i = 0; i < n; i++) {
            f_components.insert(f_dsu.find_set(i));
            g_components.insert(g_dsu.find_set(i));
        }

        // merge missing comps together
        ans += f_components.size() - g_components.size();

        cout << ans << endl;

    }
}
