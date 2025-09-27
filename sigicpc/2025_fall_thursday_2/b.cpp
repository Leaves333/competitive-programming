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

struct uwu {
    ll val, idx, ans;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<uwu> nums(n);
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            nums[i] = {x, i, -1};
        }

        sort(nums.begin(), nums.end(), [](const uwu &a, const uwu &b) {
            return a.val < b.val;
        });

        vll psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i].val;
        }

        nums[n - 1].ans = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            nums[i].ans = i;
            if (psum[i + 1] >= nums[i + 1].val) {
                nums[i].ans = nums[i + 1].ans;
            }
        }

        sort(nums.begin(), nums.end(), [](const uwu &a, const uwu &b) {
            return a.idx < b.idx;
        });

        for (uwu x : nums) {
            cout << x.ans << " ";
        }
        cout << endl;

    }
}
