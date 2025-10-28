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

void dfs(int x, vi &cur_path, vvi &ans, const vvi &edges) {
    cur_path.push_back(x);
    if (edges[x].size() == 0) {
        ans.push_back(cur_path);
        return;
    }

    dfs(edges[x][0], cur_path, ans, edges);

    for (int i = 1; i < edges[x].size(); i++) {
        vi new_path;
        dfs(edges[x][i], new_path, ans, edges);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vvi edges(n + 1);
        int root = -1;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x == i) {
                root = x;
                continue;
            }
            edges[x].push_back(i);
        }

        vvi ans;
        vi starting_path;
        dfs(root, starting_path, ans, edges);

        cout << ans.size() << endl;
        for (auto path : ans) {
            cout << path.size() << endl;
            for (auto x : path) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
