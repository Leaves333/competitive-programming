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

    vll powers(21);
    ll val = 1;
    for (int i = 0; i < 21; i++) {
        powers[i] = val;
        val *= 3;
    }

    vll prices(20);
    prices[0] = 3;
    for (ll exp = 1; exp < 20; exp++) {
        prices[exp] = powers[exp + 1] + exp * powers[exp - 1];
    }

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll ans = 0;
        int exp = 0;
        while (n > 0) {
            int m = n % 3;
            ans += m * prices[exp];
            exp++;
            n /= 3;
        }
        cout << ans << endl;
    }
}
