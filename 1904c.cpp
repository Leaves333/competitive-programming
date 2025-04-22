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
        ll n, k;
        cin >> n >> k;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if (k >= 3) {
            cout << 0 << endl;
        } else if (k == 0) {
            ll ans = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                ans = min(ans, nums[i]);
            }
            cout << ans << endl;
        } else {
            sort(nums.begin(), nums.end());
            ll ans = nums[0];
            for (int i = 1; i < n; i++) {
                ans = min(ans, nums[i] - nums[i-1]);
                ans = min(ans, nums[i]);
            }
            cout << ans << endl;
        }
    }
}
