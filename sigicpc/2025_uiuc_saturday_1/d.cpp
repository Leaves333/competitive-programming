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

    int n; cin >> n;
    vll x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vll psum_x(n + 1), psum_y(n + 1);
    for (int i = 0; i < n; i++) {
        psum_x[i + 1] = x[i] + psum_x[i];
        psum_y[i + 1] = y[i] + psum_y[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (x[i] * (i + 1)) - psum_x[i + 1];
        ans += (y[i] * (i + 1)) - psum_y[i + 1];
    }
    cout << ans << endl;
}
