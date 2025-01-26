#include <vector>
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
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vi> grid(n, vi(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int low = 1, high = min(n, m);
        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            vector<vi> psum(n + 1, vi(m + 1));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (grid[i - 1][j - 1] >= mid) {
                        psum[i][j] += 1;
                    }
                    psum[i][j] += psum[i-1][j] + psum[i][j-1];
                    psum[i][j] -= psum[i-1][j-1];
                }
            }

            bool good = false;
            for (int i = 0; i <= n - mid && !good; i++) {
                for (int j = 0; j <= m - mid; j++) {
                    int sum = psum[i][j] + psum[i + mid][j + mid];
                    sum -= psum[i + mid][j] + psum[i][j + mid];
                    if (sum == mid * mid) {
                        good = true;
                        break;
                    }
                }
            }
            
            if (good) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        cout << low << endl;

    }
}
