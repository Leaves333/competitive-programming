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
        string s; cin >> s;

        bool good = true;
        if (s[0] == 's') {
            bool first = true, second = true;
            // all s and then one p
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == 'p') {
                    first = false;
                    break;
                }
            }
            // s and then all ps
            for (int i = 1; i < n; i++) {
                if (s[i] == 's') {
                    second = false;
                    break;
                }
            }
            /*cout << first << " " << second << endl;*/
            good = first || second;
        } else if (s[0] == 'p') {
            // all p
            for (int i = 1; i < n; i++) {
                if (s[i] == 's') {
                    good = false;
                    break;
                }
            }
        } else {
            bool first = true;
            bool second = true;
            bool third = true;
            // check both cases
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == 'p') {
                    first = false;
                    break;
                }
            }
            for (int i = 1; i < n; i++) {
                if (s[i] == 's') {
                    second = false;
                    break;
                }
            }
            for (int i = 1; i < n; i++) {
                if (s[i] == 's') {
                    third = false;
                    break;
                }
            }
            good = first || second || third;
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
