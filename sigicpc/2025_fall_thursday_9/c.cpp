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

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        // case: both are even
        // max of a*k + b/k
        // need to have the same parity
        // a*k always even if a is even, otherwise same as parity of k
        // b/k even as long as there is a 2 in the factorization.
        //
        // however, removing these 2s will always cause a to be even.
        // so if a is odd and b is even, it is not possible.

        if (a % 2 == 0 && b % 2 == 1) {
            cout << -1 << endl;
        } else if (a % 2 == 1 && b % 2 == 1) {
            cout << a * b + 1 << endl;
        } else if (a % 2 == 1 && b % 4 != 0) {
            cout << -1 << endl;
        } else {
            cout << a * (b / 2) + 2 << endl;
        }
    }
}
