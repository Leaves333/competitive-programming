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

int dfs(int x, int y, vector<vector<bool>> &visited, const vector<vi> &nums) {
    visited[x][y] = true;
    int sum = nums[x][y];
    int changes[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto c : changes) {
        int new_x = x + c[0];
        int new_y = y + c[1];
        if (new_x < 0 || new_x >= nums.size() || new_y < 0 ||
            new_y >= nums[0].size())
            continue;
        if (visited[new_x][new_y])
            continue;
        if (nums[new_x][new_y] == 0)
            continue;
        sum += dfs(new_x, new_y, visited, nums);
    }
    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vi> nums(n, vi(m));
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> nums[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && nums[i][j] != 0) {
                    int val = dfs(i, j, visited, nums);
                    ans = max(ans, val);
                }
            }
        }

        cout << ans << endl;
    }
}
