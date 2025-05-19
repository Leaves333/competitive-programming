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
        int n; cin >> n;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        ll ans = 0;
        for (auto x : nums)
            ans += x;

        while (nums.size() > 1) {
            vll new_nums;
            ll sum = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                ll diff = nums[i + 1] - nums[i];
                sum += diff;
                new_nums.push_back(diff);
            }
            ans = max(ans, abs(sum));
            nums = new_nums;
        }

        cout << ans << endl;
    }
}
