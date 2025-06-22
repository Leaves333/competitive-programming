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
        vi nums(n-1);
        vi ans(n);

        for (int i = 0; i < n - 1; i++) {
            cin >> nums[i];
        }

        if (n == 2) {
            cout << nums[0] << " 0" << endl;
            continue;
        }

        ans.front() = nums.front();
        ans.back() = nums.back();
        for (int i = 0; i < n-2; i++) {
            if (ans[i] < nums[i]) {
                ans[i+1] = nums[i];
            } else {
                ans[i+1] = min(nums[i], nums[i+1]);
            }
        }

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
