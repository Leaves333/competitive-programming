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
        ll n, k, x;
        cin >> n >> k >> x;

        ll smol = (k * (k + 1)) / 2;
        ll big = k * (n + n - k + 1) / 2;

        if (x >= smol && x <= big) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
