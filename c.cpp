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

    int n, a, b;
    cin >> n >> a >> b;

    DSU first, second;
    first.init_dsu(n + 1);
    second.init_dsu(n + 1);

    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        first.union_sets(x, y);
    }

    for (int i = 0; i < b; i++) {
        int x, y;
        cin >> x >> y;
        second.union_sets(x, y);
    }

    vector<pii> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (first.find_set(i) == first.find_set(j))
                continue;
            if (second.find_set(i) == second.find_set(j))
                continue;
            ans.push_back({i, j});
            first.union_sets(i, j);
            second.union_sets(i, j);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }

}
