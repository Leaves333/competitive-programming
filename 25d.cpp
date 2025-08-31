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

    int n; cin >> n;
    DSU dsu;
    dsu.init_dsu(n + 1);

    vector<pii> extra_edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (dsu.find_set(u) != dsu.find_set(v)) {
            dsu.union_sets(u, v);
        } else {
            extra_edges.push_back({u, v});
        }
    }

    vector<pii> new_edges;
    for (int j = 2; j <= n; j++) {
        if (dsu.find_set(1) != dsu.find_set(j)) {
            new_edges.push_back({1, j});
            dsu.union_sets(1, j);
        }
    }

    cout << extra_edges.size() << endl;
    for (int i = 0; i < extra_edges.size(); i++) {
        pii extra = extra_edges[i];
        pii newe = new_edges[i];
        cout << extra.first << " " << extra.second << " " << newe.first << " " << newe.second << endl;
    }
}
