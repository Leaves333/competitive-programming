#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        ll psum[1001][1001];
        memset(psum, 0, sizeof(psum));

        for (int i = 0; i < n; i++) {
            ll h, w;
            cin >> h >> w;
            psum[h][w] += h * w;
        }

        for (int i = 1; i < 1001; i++) {
            for (int j = 1; j < 1001; j++) {
                psum[i][j] += psum[i][j-1] + psum[i-1][j];
                psum[i][j] -= psum[i-1][j-1];
            }
        }

        while (q--) {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            x--;
            y--;
            
            ll sum = psum[x][y];
            sum -= psum[x][b];
            sum -= psum[a][y];
            sum += psum[a][b];
            cout << sum << endl;
        }
    }
}
