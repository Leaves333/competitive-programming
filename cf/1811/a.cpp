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

    int t; cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        string s;
        cin >> s;

        string ans = "";
        if (d == 0) {
            cout << s + to_string(d) << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            string tmp = "";
            // cout << "checking s[i] = " << s[i] << endl;
            if (stoi(tmp + s[i]) < d) {
                // break, we insert d here
                // cout << "breaking" << endl;
                ans = s.substr(0, i) + to_string(d) + s.substr(i);
                break;
            }
        }

        if (ans == "") {
            ans = s + to_string(d);
        }

        cout << ans << endl;
    }
}
