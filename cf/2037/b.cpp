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
        int k; cin >> k;
        vi arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        int target = k - 2;
        set<int> seen;
        for (int x : arr) {
            if (target % x == 0 && seen.count(target / x)) {
                cout << x << " " << target / x << endl;
                break;
            }
            seen.insert(x);
        }
    }
}
