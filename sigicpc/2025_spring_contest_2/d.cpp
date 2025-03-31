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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        ll num_open = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == ')') {
                if (num_open <= 0)
                    ans++;
                else
                    num_open--;
            } else {
                num_open++;
            }
        }
        cout << ans << endl;
    }
}
