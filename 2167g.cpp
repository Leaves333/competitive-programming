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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vll arr(n);
        vll costs(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> costs[i];
            sum += costs[i];
        }

        // interested in finding a non-decreasing subsequence with the most
        // weight, not longest
        // LIS works by storing "smallest value that a LIS of len k can end at"
        // let dp[i] be the maximum sum of a LIS that ends at index i

        vll dp(n);
        ll max_lis = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = costs[i];
            for (int j = 0; j < i; j++) {
                if (arr[i] >= arr[j]) {
                    dp[i] = max(dp[i], dp[j] + costs[i]);
                }
            }
            max_lis = max(max_lis, dp[i]);
        }

        cout << sum - max_lis << endl;

    }
}
