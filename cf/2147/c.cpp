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
        int n;
        cin >> n;
        string s;
        cin >> s;

        // pair each single rabbit with another one
        // rabbits on the edge don't need to be paired.
        // if chain of rabbits on edge: ok.
        // if chain of rabbits in middle: needs even length.

        // ok this is jank code.

        vvi rabbit_chains;
        vi cur_chain;
        int last_rabbit = -2;
        int cur_len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                last_rabbit = i;
                cur_len++;
            } else {
                if (cur_len > 0)
                    cur_chain.push_back(cur_len);
                cur_len = 0;
            }

            if (i - last_rabbit >= 2) {
                if (cur_chain.size() > 0) {
                    rabbit_chains.push_back(cur_chain);
                    cur_chain.clear();
                }
            }
        }
        if (cur_len > 0)
            cur_chain.push_back(cur_len);
        if (cur_chain.size() > 0)
            rabbit_chains.push_back(cur_chain);


        bool good = true;
        int l = 0, r = rabbit_chains.size();
        if (s[0] == '0')
            l++;
        if (s[n - 1] == '0')
            r--;

        // cout << "l=" << l << ", r=" << r << endl;
        for (int i = l; i < r; i++) {
            // bad if chain contains only ones, and is odd length
            bool only_ones = true;
            for (auto x : rabbit_chains[i]) {
                if (x != 1) {
                    only_ones = false;
                    break;
                }
            }
            // cout << "checking chain " << i << " ...";
            if (only_ones && rabbit_chains[i].size() % 2 == 1) {
                // cout << "bad!" << endl;
                good = false;
                break;
            }
                // cout << "ok" << endl;
        }

        // cout << "rabbit_chains:" << endl;
        // for (auto v : rabbit_chains) {
        //     for (auto x : v) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        //
        //
        cout << (good ? "YES" : "NO") << endl;
        // cout << endl;
    }
}
