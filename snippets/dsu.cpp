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

    // initializes the DSU with `n` elements, all disjoint from each other
    void init_dsu(int n) {
        parent = vi(n);
        size = vi(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // returns the representative element of the set that `v` belongs to
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    // returns the size of the set containing `v`
    int get_size(int v) { return size[find_set(v)]; }

    // unions the sets containing `a` and `b`.
    // does nothing if `a` and `b` are already in the same set
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
