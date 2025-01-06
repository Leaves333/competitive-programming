#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll t;
    cin >> t;
    while (t--) {
        ll k, x, a;
        cin >> k >> x >> a;

        ll amount_spent = 0;
        bool good = true;
        for (ll i = 0; i <= x; i++) {
            ll bet = 1 + (amount_spent) / (k - 1);
            amount_spent += bet;
            if (amount_spent > a) {
                cout << "NO" << endl;
                good = false;
                break;
            }
        }

        if (good)
            cout << "YES" << endl;
    }
}
