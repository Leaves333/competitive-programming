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
        int n; cin >> n;
        map<int, int> ct;
        while (n--) {
            int x; cin >> x;
            ct[x]++;
        }

        int ans = 0;
        for (const auto [key, val] : ct) {
            ans += val / 2;
        }
        cout << ans << endl;
    }
}
