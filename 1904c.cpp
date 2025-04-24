#include <algorithm>
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

        sort(nums.begin(), nums.end());
        if (k >= 3) {
            cout << 0 << endl;
        } else if (k == 0) {
            cout << nums[0] << endl;
        } else if (k == 1) {
            ll ans = nums[0];
            for (int i = 1; i < n; i++) {
                ans = min(ans, nums[i] - nums[i-1]);
            }
            cout << ans << endl;
        } else if (k == 2) {

            ll ans = nums[0];
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    ll val = nums[j] - nums[i];
                    auto it = lower_bound(nums.begin(), nums.end(), val);
                    if (it != nums.end())
                        ans = min(ans, *it - val);
                    if (it != nums.begin())
                        ans = min(ans, val - *(it - 1));
                }
            }

            for (int i = 1; i < n; i++) {
                ans = min(ans, nums[i] - nums[i-1]);
            }
            cout << ans << endl;

        }
    }
}
