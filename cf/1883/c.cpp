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
        int n, k;
        cin >> n >> k;
        vi vals(n);
        for (int i = 0; i < n; i++) {
            cin >> vals[i];
        }

        if (k != 4) {
            int ans = INT_MAX;
            for (int v : vals) {
                if (v % k == 0) {
                    ans = min(ans, 0);
                } else {
                    ans = min(ans, k - v % k);
                }
            }
            cout << ans << endl;
        } else {
            int count_twos = 0;
            int count_odd = 0;

            int ans = INT_MAX;
            for (int v : vals) {
                if (v % 2 == 0) {
                    count_twos++;
                } else {
                    count_odd++;
                }
                if (v % k == 0) {
                    ans = min(ans, 0);
                } else {
                    ans = min(ans, k - v % k);
                }
            }

            if (count_twos >= 2)
                ans = min(ans, 0);
            if (count_odd >= 2)
                ans = min(ans, 2);
            if (count_twos >= 1 && count_odd >= 1)
                ans = min(ans, 1);
            cout << ans << endl;
        }
    }
}
