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

int n, k;

// does dfs to calculate the size of subtree rooted at x
// and stores result in sz
void dfs(int x, int parent, vi &sz, const vvi &edges) {
    sz[x] = 1;
    for (int neighbor : edges[x]) {
        if (neighbor == parent) {
            continue;
        }
        dfs(neighbor, x, sz, edges);
        sz[x] += sz[neighbor];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        vvi edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vi sz(n + 1);
        dfs(1, -1, sz, edges);

        ll ans = n;
        for (int i = 1; i <= n; i++) {
            if (sz[i] >= k) {
                ans += n - sz[i];
            }
            if (n - sz[i] >= k) {
                ans += sz[i];
            }
        }

        cout << ans << endl;
    }
}
