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
        int n; cin >> n;

        string ans = "";
        int prev_sum = -1;
        bool got_response = false;
        for (int i = 1; i < n; i++) {

            // do queries of len 2 until you get something...
            if (!got_response) {
                cout << "? " << i << " " << i + 1 << endl;
                int response; cin >> response;
                if (response == 1) {
                    cout << "? " << 1 << " " << i + 1 << endl;
                    int zeroes; cin >> zeroes;
                    int ones = i + 1 - ans.length() - zeroes;
                    for (int j = 0; j < ones - 1; j++) {
                        ans += "1";
                    }
                    for (int j = 0; j < zeroes; j++) {
                        ans += "0";
                    }
                    ans += "1";
                    prev_sum = zeroes;
                    got_response = true;
                }

            // do queries of the whole string and see when the number goes up
            } else {
                cout << "? " << 1 << " " << i + 1 << endl;
                int response; cin >> response;
                if (response > prev_sum) {
                    prev_sum = response;
                    ans += "1";
                } else {
                    ans += "0";
                }
            }
        }

        if (ans == "") {
            cout << "! IMPOSSIBLE" << endl;
        } else {
            cout << "! " << ans << endl;
        }
    }
}
