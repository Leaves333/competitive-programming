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
        string s;
        cin >> s;

        int n = s.length();
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            if (i < n - 1) {
                if (s[i] == s[i + 1]) {
                    found = true;
                    cout << s.substr(i, 2) << endl;
                }
            }
            if (i < n - 2) {
                set<char> distinct;
                distinct.insert(s[i]);
                distinct.insert(s[i + 1]);
                distinct.insert(s[i + 2]);
                if (distinct.size() == 3) {
                    found = true;
                    cout << s.substr(i, 3) << endl;
                }
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }
}
