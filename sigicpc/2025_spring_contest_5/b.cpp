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
        string s; cin >> s;

        int first_zero = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                first_zero = i;
                break;
            }
        }

        if (first_zero == -1) {
            cout << "1 1 1 " << s.length() << endl;
            continue;
        }

        int best_start = -1, best_bits = -1;
        for (int i = 0; i <= first_zero; i++) {

            int cur_bits = 0;
            for (int j = 0; j < s.length() - first_zero; j++) {
                if (s[i + j] == s[first_zero + j])
                    break;
                cur_bits++;
            }

            if (cur_bits > best_bits) {
                best_bits = cur_bits;
                best_start = i;
            }


        }

        cout << best_start + 1 << " " << best_start + s.length() - first_zero << " " << 1 << " " << s.length() << endl;

    }
}
