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
        ll n, m;
        cin >> n >> m;

        vll petals(n);
        vll quantity(n);
        for (int i = 0; i < n; i++) {
            cin >> petals[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> quantity[i];
        }

        map<ll, ll> flowers;
        for (int i = 0; i < n; i++) {
            flowers[petals[i]] = quantity[i];
        }

        for (const auto &[key, _] : flowers) {
            if (!flowers.count(key + 1))
                continue;

            ll a = flowers[key];
            ll b = flowers[key + 1];
        }
    }
}
