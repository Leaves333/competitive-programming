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
        vvi psum(n + 1, vi(32, 0)); // n by 32
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            for (int k = 0; k < 32; k++) {
                if (x & (1 << k))
                    psum[i][k]++;
                psum[i][k] += psum[i-1][k];
            }
        }

        int q; cin >> q;
        while (q--) {
            int l, k; cin >> l >> k;
            l--;
            int low = l, high = n;
            while (low < high) {
                int mid = low + (high - low + 1) / 2;
                int diff = mid - l;

                int and_sum = 0;
                for (int i = 0; i < 32; i++) {
                    if (psum[mid][i] - psum[l][i] == diff)
                        and_sum |= (1 << i);
                }
                
                if (and_sum >= k) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }

            if (low == l) {
                cout << -1 << " ";
            } else {
                cout << low << " ";
            }
        }
        cout << endl;
    }
}
