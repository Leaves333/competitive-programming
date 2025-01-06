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
        int n, k;
        cin >> n >> k;
        map<int, int> ct;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ct[x]++;
        }

        vector<int> freqs;
        for (const auto &[key, val] : ct) {
            freqs.push_back(val);
        }
        sort(freqs.begin(), freqs.end());

        int i = 0;
        while (freqs[i] <= k && i < freqs.size()) {
            k -= freqs[i];
            i++;
        }

        cout << max(1, (int)freqs.size() - i) << endl;

    }
}
