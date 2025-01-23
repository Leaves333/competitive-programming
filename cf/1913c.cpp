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
    vi count(31, 0);
    while (t--) {
        int t, v;
        cin >> t >> v;
        
        if (t == 1) {
            count[v]++;
        } else {
            int carry = 0;
            bool good = true;
            for (int i = 0; i < 30; i++) {
                int cur = count[i] + carry;
                if (v & 1 << i) {
                    cur -= 1;
                    if (cur < 0) {
                        good = false;
                        break;
                    }
                }
                carry = cur / 2;
            }
            if (good) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }
}
