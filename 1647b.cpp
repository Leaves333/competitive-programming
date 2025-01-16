#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// arr is xmin, xmax, ymin, ymax
void dfs(int x, int y, vector<vector<bool>> &visited,
         const vector<string> &grid, array<int, 4> &arr) {
    arr[0] = min(arr[0], x);
    arr[1] = max(arr[1], x);
    arr[2] = min(arr[2], y);
    arr[3] = max(arr[3], y);
    visited[x][y] = true;
    int changes[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto c : changes) {
        int new_x = x + c[0];
        int new_y = y + c[1];
        if (new_x < 0 || new_x >= grid.size() || new_y < 0 ||
            new_y >= grid[0].length())
            continue;
        if (visited[new_x][new_y])
            continue;
        if (grid[new_x][new_y] == '0')
            continue;
        dfs(new_x, new_y, visited, grid, arr);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector<vector<bool>> visited(n, vector<bool>(m));
        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    array<int, 4> arr = {i, i, j, j};
                    dfs(i, j, visited, grid, arr);
                    for (int x = arr[0]; x <= arr[1]; x++) {
                        for (int y = arr[2]; y <= arr[3]; y++) {
                            if (grid[x][y] == '0') {
                                good = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
