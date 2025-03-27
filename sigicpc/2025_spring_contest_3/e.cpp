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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vvll arr(n, vll(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        int low = 1, high = min(n, m);
        while (low < high) {

            int mid = low + (high - low + 1) / 2;
            
            vvll psum(n + 1, vll(m + 1, 0));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (arr[i-1][j-1] >= mid)
                        psum[i][j] = 1;
                    psum[i][j] += psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];
                }
            }

            bool ok = false;
            for (int i = mid; i <= n; i++) {
                for (int j = mid; j <= m; j++) {
                    int sum = psum[i][j] - psum[i-mid][j] - psum[i][j-mid] + psum[i-mid][j-mid];
                    if (sum == mid * mid)
                        ok = true;
                }
            }

            if (ok) {
                low = mid;
            } else {
                high = mid - 1;
            }

        }

        cout << low << endl;

    }
}
