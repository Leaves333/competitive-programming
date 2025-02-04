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
        int n; cin >> n;
        set<int> a, b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.insert(x);
        }
        if (a.size() + b.size() > 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
