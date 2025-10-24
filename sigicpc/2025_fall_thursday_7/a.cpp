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
        ll n; cin >> n;
        map<ll, ll> freq;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            freq[x]++;
        }

        if (freq.size() == 1) {
            cout << n * (n-1) << endl;
            continue;
        }
        auto beg = freq.begin();
        auto end = (--freq.end());
        cout << beg->second * end->second * 2 << endl;
    }
}
