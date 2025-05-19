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
        vll nums(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> nums[i];
        }
        sort(all(nums));

        vll ans(2 * n + 1);
        for (int i = 0; i < n + 1; i++) {
            ans[2 * i] = nums[2 * n - 1 - i];
        }
        for (int i = 0; i < n - 1; i++) {
            ans[2 * i + 1] = nums[i];
        }

        ll missing = 0;
        for (int i = 0; i < n - 1; i++) {
            missing -= nums[i];
        }
        for (int i = n - 1; i < 2 * n; i++) {
            missing += nums[i];
        }
        ans[2 * n - 1] = missing;

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
