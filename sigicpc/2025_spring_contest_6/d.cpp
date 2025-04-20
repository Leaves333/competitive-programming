#include <regex>
#include <strings.h>
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

int n, m, k;
int idx(int x, int y) {
    return x * m + y;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;

    vvi grid(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    DSU dsu;
    dsu.init_dsu((n + 1) * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                dsu.union_sets(idx(i, j), idx(i, j + 1));
            } else if (grid[i][j] == 2) {
                dsu.union_sets(idx(i, j), idx(i + 1, j));
            } else if (grid[i][j] == 3) {
                dsu.union_sets(idx(i, j), idx(i, j - 1));
            }
        }
    }

    map<int, int> ans;
    for (int top = 0; top < m; top++) {
        for (int bot = 0; bot < m; bot++) {
            if (dsu.find_set(idx(0, top)) == dsu.find_set(idx(n, bot))) {
                ans[top] = bot;
                break;
            }
        }
    }

    while (k--) {
        int t; cin >> t;
        cout << ans[t] + 1 << " ";
    }
    cout << endl;
}
