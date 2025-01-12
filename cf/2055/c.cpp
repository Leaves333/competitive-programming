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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vll> heights(n, vll(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> heights[i][j];
            }
        }

        // assume target sum is 0
        ll target_sum = 0;
        int x = 0, y = 0;
        if (s[0] == 'R') {
            // use column to determine sum
            ll cur_sum = 0;
            for (int i = 0; i < n; i++)
                cur_sum += heights[i][0];
            heights[0][0] = cur_sum * -1;
            y++;
        } else {
            // use row to determine sum
            ll cur_sum = 0;
            for (int i = 0; i < m; i++)
                cur_sum += heights[0][i];
            heights[0][0] = cur_sum * -1;
            x++;
        }

        s += "R";
        for (int i = 1; i < s.length(); i++) {
            char dir = s[i];
            ll cur_sum = 0;
            if (dir == 'R') {
                // use column to determine sum
                for (int j = 0; j < n; j++)
                    cur_sum += heights[j][y];
            } else {
                // use row to determine sum
                for (int j = 0; j < m; j++)
                    cur_sum += heights[x][j];
            }
            heights[x][y] = target_sum - cur_sum;

            if (dir == 'R') {
                y++;
            } else {
                x++;
            }
        }

        for (auto row : heights) {
            for (auto x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
