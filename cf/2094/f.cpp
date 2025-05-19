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
        int n, m, k;
        cin >> n >> m >> k;

        bool place_horizontally = true;
        place_horizontally = (n % k == 0);

        vvi ans(n, vi(m));
        if (n % k == 0 && m % k == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = (i + j) % k + 1;
                }
            }
        } else if (place_horizontally) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = (x % k) + 1;
                    x++;
                }
            }
        } else {
            int x = 0;
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    ans[i][j] = (x % k) + 1;
                    x++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " "; 
            }
            cout << endl;
        }
    }
}
