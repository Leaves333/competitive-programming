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

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        s += "L";

        vll dp(n + 1, INT_MAX); // min amount needed to swim
        for (int i = 0; i <= n; i++) {
            if (s[i] == 'C') {
                dp[i] = INT_MAX;
                continue;
            }
            for (int j = 1; j <= m; j++) {
                int idx = i - j;
                if (idx < 0)
                    dp[i] = 0;
                else if (s[idx] == 'L')
                    dp[i] = min(dp[i], dp[idx]);
            }
            if (i > 0)
                dp[i] = min(dp[i], dp[i - 1] + 1);
        }

        if (dp.back() > k)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
