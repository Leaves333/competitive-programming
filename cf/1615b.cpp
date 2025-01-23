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

    vector<vi> psum(20, vi(200001));
    for (int i = 0; i < 200000; i++) {
        for (int j = 0; j < 20; j++) {
            psum[j][i + 1] = ((i + 1) & (1 << j)) ? psum[j][i] + 1 : psum[j][i];
        }
    }

    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        vi count(20);
        for (int i = 0; i < 20; i++) {
            count[i] = psum[i][r] - psum[i][l - 1];
            /*cout << i << " : " << count[i] << endl;*/
        }

        int ans = INT_MAX;
        for (auto x : count) {
            ans = min(ans, r - l + 1 - x);
        }
        cout << ans << endl;
    }
}
