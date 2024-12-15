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
        string s; cin >> s;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'p') {
                ans += 'q';
            } else if (s[i] == 'q') {
                ans += 'p';
            } else {
                ans += 'w';
            }
        }
        cout << ans << endl;
    }
}
