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

    ll n, t;
    cin >> n >> t;
    vll books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    ll ans = 0;
    ll l = 0, r = 0, sum = 0;
    while (r < n) {
        sum += books[r];
        r++;
        while (sum > t) {
            sum -= books[l];
            l++;
        }
        ans = max(ans, r - l);
    }
    cout << ans << endl;
}
