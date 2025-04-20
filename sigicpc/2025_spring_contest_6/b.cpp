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

int dfs(int x, int y, const vvi &grid, vvi &visited) {

    const vvi directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    stack<pii> stk;
    stk.push({x, y});

    int ans = 0;
    while (!stk.empty()) {

        int x = stk.top().first;
        int y = stk.top().second;
        stk.pop();
        if (visited[x][y])
            continue;

        visited[x][y] = true;
        ans += grid[x][y];

        for (auto d : directions) {
            int new_x = x + d[0];
            int new_y = y + d[1];
            if (new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size())
                continue;
            if (grid[new_x][new_y] == 0)
                continue;
            stk.push({new_x, new_y});
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vvi grid(n, vi(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int ans = 0;
        vvi visited(n, vi(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, grid, visited));
                }
            }
        }

        cout << ans << endl;
    }
}
