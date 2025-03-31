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

        vll psum(n + 1);
        for (int i = 0; i < n; i++) {
            psum[i + 1] = psum[i] + s[i] - '0' - 1;
        }

        map<ll, int> seen;
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += seen[psum[i]];
            seen[psum[i]]++;
        }
        cout << ans << endl;
    }
}
