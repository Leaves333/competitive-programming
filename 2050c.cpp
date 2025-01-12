#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int twos = 0, threes = 0;
        int sum = 0;
        for (char c : s) {
            if (c == '2') {
                twos++;
            }
            if (c == '3') {
                threes++;
            }
            sum += c - '0';
        }

        sum %= 9;
        vector<bool> dp(30, false);
        twos = min(twos, 15);
        threes = min(threes, 15);
        dp[sum] = true;

        while (twos--) {
            for (int i = 29; i >= 0; i--) {
                if (i-2 >= 0 && dp[i-2]) {
                    dp[i] = true;
                }
            }
        }
        while (threes--) {
            for (int i = 29; i >= 0; i--) {
                if (i-6 >= 0 && dp[i-6]) {
                    dp[i] = true;
                }
            }
        }

        if (dp[0] || dp[9] || dp[18] || dp[27]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
