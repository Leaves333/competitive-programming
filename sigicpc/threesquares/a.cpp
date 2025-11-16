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
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 's')
                continue;
            if (i == 0) {
                s[i] = 's';
                ans++;
            } else if (i == s.length() - 1) {
                s[i] = 's';
                ans++;
            } else {
                if (s[i-1] != 's') {
                    s[i-1] = 's';
                    ans++;
                }
                if (s[i+1] != 's') {
                    s[i+1] = 's';
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
