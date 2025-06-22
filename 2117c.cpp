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
        vi nums(n);
        vi count(n);
        set<int> seen;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            seen.insert(nums[i]);
            count[i] = seen.size();
        }

        int l = n-1, r = n-1;
        int ans = 0;

        seen.clear();
        while (l >= 0) {
            seen.insert(nums[l]);
            if (seen.size() >= count[r]) {
                r = l - 1;
                seen.clear();
                ans++;
            }
            l--;
        }
        cout << ans << endl;
    }
}
