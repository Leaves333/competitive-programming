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

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi nums(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
            if (sum < 0)
                sum += MOD;
            else
                sum %= MOD;
        }

        ll max_sum = 0;
        ll cur_sum = 0;
        ll smol = 0;
        for (int i = 0; i < n; i++) {
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum - smol);
            smol = min(smol, cur_sum);
        }

        for (int i = 0; i < k; i++) {
            sum += max_sum;
            max_sum += max_sum;
            sum %= MOD;
            max_sum %= MOD;
        }

        cout << sum << endl;
    }
}
