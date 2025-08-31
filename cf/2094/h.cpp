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

vi factorize(int k) {
    vi factors;
    for (int i = 1; i < sqrt(k) + 1; i++) {
        if (k % i == 0) {
            factors.push_back(i);
            factors.push_back(k / i);
        }
    }
    return factors;
}

ll f(int k, const vi &a, const vvi &idx, int l, int r) {

    vi factors = factorize(k);
    set<int> indices;
    for (int f : factors) {
        auto it = lower_bound(idx[f].begin(), idx[f].end(), l);
        if (it == idx[f].end() || *it > r)
            continue;
        indices.insert(*it);
    }

    ll ans = 0;
    ll last_idx = l;
    for (int i : indices) {
        ans += (i - last_idx) * k;
        while (k % a[i] == 0)
            k /= a[i];
        last_idx = i;
    }

    ans += (r - last_idx + 1) * k;
    return ans;
}

vvi idx(100001);

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < idx.size(); i++) {
            idx[i].clear();
        }

        vi a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            idx[a[i]].push_back(i);
        }

        while (q--) {
            int k, l, r;
            cin >> k >> l >> r;
            cout << f(k, a, idx, l, r) << endl;
        }
    }
}
