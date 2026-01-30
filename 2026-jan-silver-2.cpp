#include <algorithm>
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

struct constraint {
    ll dest, sum;
};

vll left_bounds, right_bounds;
vector<vector<constraint>> constraints;
vector<pll> bounds;
vb visited;

// does dfs to calculate bounds relative to parent
// returns true if no contradictions, false otherwise
bool dfs(int x, int parent, ll offset) {

    visited[x] = true;

    ll bound_one = left_bounds[x] + offset;
    ll bound_two = right_bounds[x] + offset;
    bounds[x] = {min(bound_one, bound_two), max(bound_one, bound_two)};

    bool valid = true;
    for (constraint c : constraints[x]) {
        if (!visited[c.dest]) {
            ll new_offset = -1 * (offset + c.sum);
            valid &= dfs(c.dest, parent, new_offset);
        } else {
            // we've already visited this node,
        }
    }

    return valid;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;

        left_bounds.assign(n, 0);
        right_bounds.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> left_bounds[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> right_bounds[i];
        }

        DSU dsu;
        dsu.init_dsu(n);

        vector<vector<constraint>> constraints(n);
        for (int i = 0; i < m; i++) {
            ll x, y, z;
            cin >> x >> y >> z;
            x--;
            y--;

            constraints[x].push_back({y, z});
            constraints[y].push_back({x, z});
            dsu.union_sets(x, y);
        }

        // left and right bounds for each node,
        // relative to the parent of the group
        bounds.assign(n, {0, 0});
        visited.assign(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int rep = dsu.find_set(i);
                dfs(rep, rep, 0);
            }
        }

        // what are the cases?
        // component is a tree: can do dfs.
        // component has a cycle: the cycle edge is either consistent with the
        // system, or inconsistent
    }
}
