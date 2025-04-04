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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        k = abs(k);
        if (n * p < k) {
            cout << -1 << endl;
        } else {
            cout << (k / p) + (k % p != 0) << endl;
        }
    }
}
