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
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int min_seen = INT_MAX, min_win = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++) {

            // landing on this square results in a win
            if (nums[i] < min_seen) {
                min_seen = nums[i];
            } else if (nums[i] < min_win) {
                min_win = nums[i];
                ans++;
            }

        }
        
        cout << ans << endl;

    }
}
