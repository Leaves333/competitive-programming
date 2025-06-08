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

// returns if b is less than a
bool less_than(int a, int b, int b_exp) {

    if (b_exp >= 32)
        return true;

    ll aa = a;
    ll bb = b;
    bb <<= b_exp;

    // cout << aa << " < " << bb << endl;
    return aa < bb;
}

ll factor_needed(int a, int a_exp, int b, int b_exp) {

    // cout << "factor needed: " << a << " " << b << endl;

    ll ret = b_exp;
    // cout << "inital guess: " << ret << endl;

    while (a / 2 >= b) {
        a /= 2;
        // cout << "adjusting: " << a << " " << b << endl;
        ret--;
    }
    while (a < b) {
        a *= 2;
        // cout << "adjusting: " << a << " " << b << endl;
        ret++;
    }

    // cout << ret << "!" << endl;

    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vi vals(n);
        vi factor(n);
        for (int i = 0; i < n; i++) {
            cin >> vals[i];
        }

        ll ans = 0;
        for (int i = 1; i < n; i++) {
            if (less_than(vals[i], vals[i-1], factor[i-1])) {
                ll ret = factor_needed(vals[i], factor[i], vals[i-1], factor[i-1]);
                ans += ret;
                factor[i] = ret;
            }
        }

        cout << ans << endl;

    }
}
