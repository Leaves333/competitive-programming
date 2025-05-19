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

        int n, k; cin >> n >> k;
        vi nums(n); // 1 if <= k, 0 otherwise
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] = ( nums[i] <= k ) ? 1 : -1;
        }

        vi psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + nums[i];
        }
        
        vi max_dp(n + 1), min_dp(n + 1);
        max_dp[n-1] = psum[n-1];
        min_dp[n-1] = psum[n-1];
        for (int i = n-2; i >= 0; i--) {
            max_dp[i] = max(max_dp[i+1], psum[i]);
            min_dp[i] = min(min_dp[i+1], psum[i]);
        }

        /*cout << "here's psum: ";*/
        /*for (auto x : psum) {*/
        /*    cout << x << " ";*/
        /*}*/
        /*cout << endl;*/

        /*cout << "here's max_dp: ";*/
        /*for (auto x : max_dp) {*/
        /*    cout << x << " ";*/
        /*}*/
        /*cout << endl;*/
        
        /*cout << "here's min_dp: ";*/
        /*for (auto x : min_dp) {*/
        /*    cout << x << " ";*/
        /*}*/
        /*cout << endl;*/

        bool good = false;
        for (int i = 1; i < n - 1; i++) {

            int first = psum[i];
            int second = max_dp[i+1] - psum[i];
            int third = psum[n] - max_dp[i+1];

            /*cout << "attempted: " << first << " " << second << " " << third << endl;*/

            int count = (first >= 0) + (second >= 0) + (third >= 0);
            if (count >= 2) {
                good = true;
                break;
            }

            second = min_dp[i+1] - psum[i];
            third = psum[n] - min_dp[i+1];

            /*cout << "attempted: " << first << " " << second << " " << third << endl;*/

            count = (first >= 0) + (second >= 0) + (third >= 0);
            if (count >= 2) {
                good = true;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}
