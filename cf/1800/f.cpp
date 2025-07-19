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

const bitset<26> TWENTY_SIX = 0x03FFFFFF;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<unordered_map<bitset<26>, int>> freq(26);
    for (auto &m : freq) {
        m.reserve(1 << 15);
        m.max_load_factor(0.25);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bitset<26> parity = 0;
        bitset<26> existence = 0;
        for (char c : s) {
            parity.flip(c - 'a');
            existence.set(c - 'a');
        }

        for (int k = 0; k < 26; k++) {
            if (!existence[k])
                freq[k][parity]++;
        }
        
        auto comp = parity ^ TWENTY_SIX;
        for (int k = 0; k < 26; k++) {
            if (existence[k])
                continue;
            comp.flip(k);
            ans += freq[k][comp];
            comp.flip(k);
        }


    }

    cout << ans << endl;
}
