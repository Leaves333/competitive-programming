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
        int x; cin >> x;

        int highest_bit = 0;
        for (int i = 30; i >= 0; i--) {
            if (x & (1 << i)) {
                highest_bit = 1 << i;
                break;
            }
        }

        bool all_bits_set = true;
        bool found_zero = false;
        int lowest_zero = -1;
        for (int i = 0; i <= 30; i++) {
            if (!(x & (1 << i))) {
                if (!found_zero)
                    lowest_zero = 1 << i;
                found_zero = true;
            }
            if ((x & (1 << i)) && found_zero) {
                all_bits_set = false;
            }
        }

        if (x <= 3) {
            cout << -1 << endl;
            continue;
        }
        if (x - highest_bit == 0) {
            cout << -1 << endl;
            continue;
        }
        if (all_bits_set) {
            cout << -1 << endl;
            continue;
        }

        int y = x - highest_bit + lowest_zero;
        cout << y << endl;

    }
}
