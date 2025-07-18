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
        string s;
        cin >> s;

        for (char &c : s) {
            if (c == '0')
                c = ':';
        }

        s = "1" + s;
        int ans = 4;
        for (int i = 1; i < 5; i++) {
            ans += abs(s[i] - s[i - 1]);
        }

        cout << ans << endl;
    }
}
