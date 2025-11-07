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

void dfs(int x, const vvi &edges, vb &visited, vi &size) {
    visited[x] = true;
    size[x] = 1;
    for (auto adj : edges[x]) {
        if (visited[adj])
            continue;
        dfs(adj, edges, visited, size);
        size[x] += size[adj];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vvi edges(n+1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    vb visited(n + 1, false);
    vi size(n + 1);
    dfs(1, edges, visited, size);

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (size[i] % 2 == 0) {
            ans++;
        }
    }

    cout << ans << endl;
}
