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
        vll nums(n);
        vll psum(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            psum[i + 1] = psum[i] + nums[i];
        }

        ll ans = 0;
        for (int k = 1; k <= sqrt(n) + 1; k++) {
            if (n % k != 0)
                continue;

            ll smol = LLONG_MAX, big = LLONG_MIN;
            for (int i = 0; i + k <= n; i += k) {
                ll diff = psum[i + k] - psum[i];
                smol = min(smol, diff);
                big = max(big, diff);
            }
            ans = max(ans, big - smol);

            int other_k = n / k;
            smol = LLONG_MAX, big = LLONG_MIN;
            for (int i = 0; i + other_k <= n; i += other_k) {
                ll diff = psum[i + other_k] - psum[i];
                smol = min(smol, diff);
                big = max(big, diff);
            }
            ans = max(ans, big - smol);
        }

        cout << ans << endl;
    }
}
