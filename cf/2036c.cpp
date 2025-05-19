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

    int t; cin >> t;
    while (t--) {

        string s;
        cin >> s;
        int q; cin >> q;

        int count = 0;
        auto pos = s.find("1100");
        while (pos != string::npos) {
            pos = s.find("1100", pos + 1);
            count++;
        }

        while (q--) {
            int k; char v;
            cin >> k >> v;
            for (int i = max(0, k - 4); i < min(k, (int) s.length() - 3); i++) {
                if (s.substr(i, 4) == "1100")
                    count--;
            }
            s[k - 1] = v;
            for (int i = max(0, k - 4); i < min(k, (int) s.length() - 3); i++) {
                if (s.substr(i, 4) == "1100")
                    count++;
            }
            if (count > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
