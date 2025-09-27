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

bool is_prime(ll n) {
    for (ll i = 2; i <= sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a - b != 1) {
            cout << "NO" << endl;
            continue;
        }
        ll x = 2 * a - 1;
        if (is_prime(x)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
