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
        string a, b, c;
        cin >> a >> b >> c;

        int dp[a.length() + 1][b.length() + 1];

        for (int i = 0; i <= a.length(); i++) {
            for (int j = 0; j <= b.length(); j++) {
                dp[i][j] = INT_MAX;
            }
        }

        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;

        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                if (c[i+j-2] == a[i-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if (c[i+j-2] == b[j-1])
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }
        }

        for (int i = 0; i <= a.length(); i++) {
            for (int j = 0; j <= b.length(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        cout << dp[a.length()][b.length()] << endl;
    }
}
