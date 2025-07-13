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

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        ll x, n, m;
        cin >> x >> n >> m;
        n = min(n, 32ll);
        m = min(m, 32ll);

        // calc min
        ll a = n, b = m;
        ll ans_min = x;
        while (b--) {
            ans_min = ((ans_min + 1) >> 1);
        }
        while (a--) {
            ans_min = (ans_min >> 1);
        }

        // calc max
        a = n, b = m;
        ll ans_max = x;
        while (a--) {
            ans_max = (ans_max >> 1);
        }
        while (b--) {
            ans_max = ((ans_max + 1) >> 1);
        }

        cout << ans_min << " " << ans_max << "\n";
    }
}
