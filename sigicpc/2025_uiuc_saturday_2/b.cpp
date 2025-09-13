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

    int n, k;
    cin >> n >> k;

    map<ll, ll> freq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    int ans = 0;
    while (true) {
        int repaired = 0;
        vi to_erase;
        for (auto &[key, val] : freq) {
            // cout << "val: " << val << ", ";
            // cout << "key - repaired: " << key - repaired << ", ";
            // cout << "k - repaired: " << k - repaired << endl;
            int num_fixed = min(val, key - repaired);
            num_fixed = min(num_fixed, k - repaired);
            val -= num_fixed;
            if (val <= 0)
                to_erase.push_back(key);
            repaired += num_fixed;
            if (repaired >= k)
                break;
        }
        for (auto x : to_erase) {
            freq.erase(x);
        }
        if (repaired < k) {
            break;
        }
        ans++;
    }

    cout << ans << endl;

}
