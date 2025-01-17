#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(all(nums));

        // all the same value
        if (nums[0] == nums[n-1]) {
            cout << n / 2 << endl;
            continue;
        }

        ll ans = 0;
        for (ll i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) 
                continue;
            ans = max(ans, (i + 1) * (n - i - 1));
        }
        cout << ans << endl;

    }
}
