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


    vector<pair<bitset<26>, bitset<26>>> odd;
    vector<pair<bitset<26>, bitset<26>>> even;

    // m[i][k] stores the number of odds with 0 as the k-th bit
    unordered_map<bitset<26>, vector<int>> m;
    m.reserve(32768);
    m.max_load_factor(0.25);

    ll ans = 0;
    bitset<26> helper;
    helper.flip();
    for (int i = 0; i < odd.size(); i++) {
        for (int j = 0; j < 26; j++) {
            helper.reset(j);
            bitset<26> key = odd[i].second ^ helper;
            helper.set(j);

            if (!m.count(key))
                m[key] = vector<int>(26);

            for (int k = 0; k < 26; k++) {
                if (!odd[i].first[k])
                    m[key][k]++;
            }
        }
    }

    for (int i = 0; i < even.size(); i++) {
        auto vec = m[even[i].second];
        for (int k = 0; k < 26; k++) {
            // i'm overcounting!!! how do i not overcount D:
            if (!even[i].first[k])
                ans += vec[k];
        }
    }

}
