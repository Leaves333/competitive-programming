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

// if we change, we always modify to be prev.
// two cases: change / no change.
vvll memo;

// returns the min cost for this suffix,
// given that value before x is nums[prev]
ll solve(int x, int prev, const vll &nums, const vll &costs) {
    if (x >= nums.size()) {
        return 0;
    }

    if (memo[x][prev] != -1) {
        return memo[x][prev];
    }

    if (nums[x] < nums[prev]) {
        // must adjust!!
        ll ans = costs[x] + solve(x + 1, prev, nums, costs);
        memo[x][prev] = ans;
        return ans;
    } else {
        // two choices: adjust or not
        ll adjust = costs[x] + solve(x + 1, prev, nums, costs);
        ll no_adjust = solve(x + 1, x, nums, costs);
        ll ans = min(adjust, no_adjust);
        memo[x][prev] = ans;
        return ans;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vll nums(n + 1, 0);
        vll costs(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            cin >> costs[i + 1];
        }

        memo.assign(n + 1, vll(n + 1, -1));
        cout << solve(1, 0, nums, costs) << endl;
    }
}
