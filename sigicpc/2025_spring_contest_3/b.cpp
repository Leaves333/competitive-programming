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
        int n, k;
        cin >> n >> k;
        vi nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        int ans = 1;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > k) {
                cur = 1;
            } else {
                cur++;
            }
            ans = max(cur, ans);
        }
        
        cout << n - ans << endl;
    }
}
