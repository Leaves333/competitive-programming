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

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vvb bad_cells(n, vb(m, false));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i-1][j] == 'X' && grid[i][j-1] == 'X') {
                bad_cells[i][j] = true;
            }
        }
    }

    vi bad_psum(m + 1, false);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (bad_cells[i][j]) {
                bad_psum[j + 1] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        bad_psum[i] += bad_psum[i - 1];
    }

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int diff = bad_psum[r] - bad_psum[l];
        if (diff == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
