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

struct SegmentTree {

    vll tree;
    void build(const vll &a) {
        tree.resize(4 * a.size());
        build(a, 1, 0, a.size() - 1);
    }

    void build(const int a) { tree = vll(4 * a); }

    void build(const vll &a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);

            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;

        return max(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
        }
    }
};

struct query {
    int l, r, x, id, ans;
};

void dfs(int x, const vi &perm, const vvi &graph, vb &visited,
         vector<vector<query>> &query_map, SegmentTree &segtree, int &timer) {

    visited[x] = true;
    segtree.update(1, 0, graph.size() - 1, perm[x], timer);
    int initial_time = timer;

    // dfs...
    for (auto dest : graph[x]) {
        if (visited[dest])
            continue;
        dfs(dest, perm, graph, visited, query_map, segtree, ++timer);
    }

    // answer queries on the way out
    for (query &q : query_map[x]) {
        int res = segtree.query(1, 0, graph.size() - 1, q.l, q.r);
        if (res >= initial_time)
            q.ans = 1;
        else
            q.ans = 0;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vvi graph(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vi perm(n + 1);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            perm[x] = i;
        }

        vector<vector<query>> query_map(n + 1);
        for (int i = 0; i < q; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            query_map[x].push_back({l, r, x, i, -1});
        }

        vb visited(n + 1, false);
        SegmentTree segtree;
        segtree.build(n + 1);
        int timer = 0;

        dfs(1, perm, graph, visited, query_map, segtree, timer);

        vector<query> all_queries;
        for (auto vec : query_map)
            for (auto qry : vec)
                all_queries.push_back(qry);

        sort(all_queries.begin(), all_queries.end(),
             [](const query &a, const query &b) { return a.id < b.id; });

        for (const query &q : all_queries) {
            cout << (q.ans == 0 ? "NO" : "YES") << endl;
        }
        cout << endl;
    }
}
