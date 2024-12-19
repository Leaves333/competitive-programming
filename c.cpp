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
        int n; cin >> n;
        if (n < 5) {
            cout << -1 << endl;
            continue;
        }

        // print all odds except 5
        for (int i = 1; i <= n; i += 2) {
            if (i == 5) continue;
            cout << i << " ";
        }
        cout << "5 4 ";
        // print all evens except 4
        for (int i = 2; i <= n; i += 2) {
            if (i == 4) continue;
            cout << i << " ";
        }
        cout << endl;
    }
}
