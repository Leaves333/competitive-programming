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

    int t; cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        cout << 1 << " ";
        if (d % 3 == 0 || n >= 3) {
            cout << 3 << " ";
        }
        if (d == 5) {
            cout << 5 << " ";
        }
        if (d == 7 || n >= 3) {
            cout << 7 << " ";
        }
        if (n >= 6) {
            cout << 9 << " ";
        } else if (d % 3 == 0 && n >= 3) {
            cout << 9 << " ";
        } else if (d == 9) {
            cout << 9 << " ";
        }
        cout << endl;
    }
}
