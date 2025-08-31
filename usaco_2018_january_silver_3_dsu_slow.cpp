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

struct edge {
    ll dest, weight;
};

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
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");

    int n, q;
    fin >> n >> q;
    vi starts(n - 1), ends(n - 1), weights(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        starts[i] = u;
        ends[i] = v;
        weights[i] = w;
    }

    while (q--) {
        int k, v;
        fin >> k >> v;

        DSU dsu;
        dsu.init_dsu(n + 1);
        for (int i = 0; i < n - 1; i++) {
            if (weights[i] >= k) {
                dsu.union_sets(starts[i], ends[i]);
            }
        }

        fout << dsu.size[dsu.find_set(v)] - 1 << endl;
    }
}
