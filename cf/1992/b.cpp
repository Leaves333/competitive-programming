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
        int n, k;
        cin >> n >> k;
        vi nums(k);
        int big = -1, ones = 0;
        for (int i = 0; i < k; i++) {
            cin >> nums[i];
            if (nums[i] == 1)
                ones++;
            big = max(big, nums[i]);
        }

        int ans = ones;
        ans += 2 * (n - big - ones);
        ans -= (k - ones - 1);
        cout << ans << endl;

    }
}
