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
        int low = 2, high = 999;
        while (low < high) {
            int a = low + (high - low + 1) / 3;
            int b = high - (high - low + 1) / 3;

            cout << "? " << a << " " << b << endl;
            int res;
            cin >> res;

            if (res == (a + 1) * (b + 1)) {
                // start
                high = a;
            } else if (res == a * (b + 1)) {
                // middle
                low = a + 1;
                high = b;
            } else {
                // end
                low = b + 1;
            }
        }

        cout << "! " << low << endl;
    }
}
