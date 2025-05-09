#include <vector>
#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int dfs(int x, int y, vvi &dp, const vector<string> &grid) {

    // out of bounds
    // this case should never happen
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].length())
        return -1;

    if (dp[x][y] != -1)
        return dp[x][y];

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vvi dp(n, vi(m, -1));
    }
}
