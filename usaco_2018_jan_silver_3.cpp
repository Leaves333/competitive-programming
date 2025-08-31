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

struct edge {
    int a, b, weight;
};

struct query {
    int idx, k, v, ans;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("mootube.in");
    ofstream cout("mootube.out");

    int n, q;
    cin >> n >> q;

    vector<edge> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(edge{u, v, w});
    }

    // sort edges by weight from high to low
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.weight > b.weight;
    });

    vector<query> queries;
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        queries.push_back(query{i, k, v, -1});
    }

    // sort queries by minimum allowed edge weight
    sort(queries.begin(), queries.end(), [](const query &a, const query &b) {
        return a.k > b.k;
    });

    // answer queries
    DSU dsu;
    dsu.init_dsu(n + 1);
    int idx = 0;
    for (int i = 0; i < queries.size(); i++) {
        query &qq = queries[i];
        while (idx < edges.size() && edges[idx].weight >= qq.k) {
            dsu.union_sets(edges[idx].a, edges[idx].b);
            idx++;
        }
        qq.ans = dsu.size[dsu.find_set(qq.v)] - 1;
    }

    // sort queries back into original order
    sort(queries.begin(), queries.end(), [](const query &a, const query &b) {
        return a.idx < b.idx;
    });

    for (const query &q : queries) {
        cout << q.ans << endl;
    }
}
