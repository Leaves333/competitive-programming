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
        int n; cin >> n;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int ans = 0;
        ll sum = nums[0], big = nums[0];
        if (nums[0] == 0)
            ans++;

        for (int i = 1; i < n; i++) {
            sum += nums[i];
            big = max(big, nums[i]);
            if (big * 2 == sum)
                ans++;
        }

        cout << ans << endl;
    }
}
