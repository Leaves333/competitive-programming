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

        const int N = 5000;
        string s; cin >> s;
        bitset<N> original(s), best;

        int target_length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                target_length = s.length() - i - 1;
            }
        }

        int l = 1, r = 1;
        while (true) {
            bool found = false;
            for (int i = 0; i < s.length() - target_length; i++) {
                if (s[i] != '1') {
                    continue;
                }
                found = true;
                bitset<N> cur(s.substr(i, target_length + 1));
                auto res = original ^ cur;
                bool res_is_greater = false;
                for (int k = N-1; k >= 0; k--) {
                    if (res[k] ^ best[k]) {
                        res_is_greater = res[k];
                        break;
                    }
                }
                if (res_is_greater) {
                    best = res;
                    l = i + 1;
                    r = i + target_length + 1;
                }
            }
            if (!found) {
                target_length--;
            } else {
                break;
            }
        }

        cout << 1 << " " << s.length() << " " << l << " " << r << endl;
    }
}
