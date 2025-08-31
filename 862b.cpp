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

void dfs(int x, const vvi &edges, vi &color) {
    for (auto dest : edges[x]) {
        if (color[dest] == -1) {
            color[dest] = !color[x];
            dfs(dest, edges, color);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vvi edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vi color(n + 1, -1);
    color[1] = 0;
    dfs(1, edges, color);

    ll a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        color[i] ? a++ : b++;
    }

    cout << (a * b) - (n - 1) << endl;
}
