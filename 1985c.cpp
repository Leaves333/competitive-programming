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
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        set<ll> targets;
        targets.insert(0);
        ll sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            targets.insert(nums[i] * 2);
            if (targets.count(sum)) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}
