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
        int n, k;
        cin >> n >> k;
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
        }

        int ans = 0;
        for (auto &[key, val] : freq) {
            int pair = freq[k - key];
            int count = min(pair, val);
            if (k - key == key)
                count = val / 2;

            val -= count;
            freq[k - key] -= count;
            ans += count;
        }
        cout << ans << endl;
    }
}
