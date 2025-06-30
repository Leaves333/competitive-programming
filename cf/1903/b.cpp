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
        vvi matrix(n, vi(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        vi ans(n, INT_MAX ^ (1 << 30));
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = 0; k <= 30; k++) {
                    if (!(matrix[i][j] & (1 << k))) {
                        // if bit isn't set, unset it from both vals
                        int mask = INT_MAX ^ (1 << k);
                        ans[i] &= mask;
                        ans[j] &= mask;
                    }
                }
            }
        }

        bool good = true;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = 0; k <= 30; k++) {
                    if (matrix[i][j] & (1 << k)) {
                        // if bit is set, check it is set in at least one
                        int mask = (1 << k);
                        int count = 0;
                        if (ans[i] & mask)
                            count++;
                        if (ans[j] & mask)
                            count++;
                        if (count == 0)
                            good = false;
                    }
                }
            }
        }

        if (good) {
            cout << "YES" << endl;
            for (auto x : ans) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
