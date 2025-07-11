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
        int n; cin >> n;
        map<ll, ll> freq;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            freq[x]++;
        }

        ll ans = 0;
        for (auto &[key, value] : freq) {
            ans += value * (value - 1) / 2;
        }
        ans += freq[1] * freq[2];
        cout << ans << endl;
    }
}
