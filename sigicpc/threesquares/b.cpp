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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vll neg_sum(n, 0);
        for (int i = 1; i < n; i++) {
            neg_sum[i] = neg_sum[i - 1] - nums[i];
        }
        vll abs_sum(n, 0);
        for (int i = 1; i < n; i++) {
            abs_sum[i] = abs_sum[i - 1] + abs(nums[i]);
        }

        // fix unused elem as 0
        ll ans = neg_sum[n - 1];
        // cout << "case 0: " << ans << endl;

        // fix unused elem as n-1
        ll tmp = nums[0] + abs_sum[n - 2];
        // cout << "case n-1: " << tmp << endl;
        ans = max(ans, tmp);

        // iterate through all other possibilities
        for (int i = 1; i < n - 1; i++) {
            tmp = nums[0] + abs_sum[i - 1] + neg_sum[n - 1] - neg_sum[i];
            // cout << "i=" << i << ": " << tmp << endl;
            ans = max(ans, tmp);
        }

        cout << ans << endl;
        // cout << endl;
    }
}
