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
        map<int, int> x;
        while (n--) {
            int k; cin >> k;
            x[k]++;
        }
        ll ans = 0;
        for (auto &[key, val] : x) {
            ans += val/2;
        }
        cout << ans << endl;
    }
}
