#include <utility>
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

    vll fib(50, 1);
    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // cout << "here's fib: " << endl;
    // for (int i = 0; i < 10; i++) {
    //     cout << fib[i] << "\t";
    // }
    // cout << endl;

    int t; cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;

        // repeatedly check squares, checking if it fits
        bool good = true;
        for (int i = n; i > 1; i--) {

            // cout << "checking i = " << i << ", ";
            // cout << "x,y = " << x << ", " << y << endl;

            // try putting a square on each side
            if (y > fib[i]) {
                // cout << x << ", " << y << " good on case 1" << endl;
                y = y - fib[i];
                swap(x, y);
                continue;
            }

            y = fib[i + 1] - y + 1;
            if (y > fib[i]) {
                // cout << x << ", " << y << " good on case 2" << endl;
                y = y - fib[i];
                swap(x, y);
                continue;
            }

            good = false;
            break;

        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}
