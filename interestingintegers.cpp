#include <bits/stdc++.h>
#include <climits>
#include <numeric>
#include <utility>
#include <vector>
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

struct fib {
    ll a, b;
};

struct ee_result {
    ll gcd, a, b;
};

// ensure a >= b before calling
ee_result extended_euclid(ll a, ll b) {

    // store intermediate computation results
    struct ee_comp {
        ll remainder, a_coeff, b_coeff;
    };
    vector<ee_comp> v;
    v.push_back({.remainder = a, .a_coeff = 1, .b_coeff = 0});
    v.push_back({.remainder = b, .a_coeff = 0, .b_coeff = 1});

    while (v.back().remainder > 0) {
        ee_comp one = v[v.size() - 1];
        ee_comp two = v[v.size() - 2];
        ll quotient = two.remainder / one.remainder;
        v.push_back({
            .remainder = two.remainder - (quotient * one.remainder),
            .a_coeff = two.a_coeff - (quotient * one.a_coeff),
            .b_coeff = two.b_coeff - (quotient * one.b_coeff),
        });
    }

    ee_comp last_nonempty_row = v[v.size() - 2];
    return {
        .gcd = last_nonempty_row.remainder,
        .a = last_nonempty_row.a_coeff,
        .b = last_nonempty_row.b_coeff,
    };
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int FIB_MAX = 50;
    vector<fib> v;
    v.push_back({.a = 1, .b = 0});
    v.push_back({.a = 0, .b = 1});
    for (int i = 0; i < FIB_MAX; i++) {
        fib one = v[v.size() - 1];
        fib two = v[v.size() - 2];
        v.push_back({.a = one.a + two.a, .b = one.b + two.b});
        cout << i << " : " << v[i].a << " " << v[i].b << endl;
    }

    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;

        // for each, check if there exists integers x, y, x <= y
        // such that ax + by = k
        // by bezouts identity, they exist if k is a multiple of gcd(a, b)
        ll x = -1, y = -1;
        for (int i = 0; i < FIB_MAX; i++) {
            fib f = v[i];

            ee_result res = extended_euclid(f.b, f.a);
        }
    }
}
