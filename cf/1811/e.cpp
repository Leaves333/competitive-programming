#include <algorithm>
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
        ll k; cin >> k;

        vi converted;
        while (k > 0) {
            converted.push_back(k % 9);
            k /= 9;
        }
        reverse(converted.begin(), converted.end());

        for (int x : converted) {
            if (x <= 3) {
                cout << x;
            } else {
                cout << x + 1;
            }
        }
        cout << endl;

    }
}
