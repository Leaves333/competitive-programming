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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vvi edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        if (n <= 3) {
            cout << 0 << endl;
            continue;
        }

        int num_leaves = 0;
        for (int i = 0; i < n + 1; i++) {
            num_leaves += edges[i].size() == 1;
        }

        int ans = num_leaves;
        for (int i = 0; i < n + 1; i++) {
            int adjacent_leaves = 0;
            for (auto adj : edges[i]) {
                adjacent_leaves += edges[adj].size() == 1;
            }
            ans = min(ans, num_leaves - adjacent_leaves);
        }

        cout << ans << endl;
    }
}
