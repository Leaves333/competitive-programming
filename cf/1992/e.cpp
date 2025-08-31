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
        int n; cin >> n;
        string base = to_string(n);
        string s = "";

        vector<pii> ans;
        for (int k = 1; k <= 7; k++) {

            s += base[(k - 1) % base.length()];
            ll target = stoll(s);

            for (int i = k + 1; i <= 10000; i++) {
                int a = i, b = (base.length() * a) - k;
                ll value = (n * a) - b;

                if (value == target) {
                    /*cout << a << " " << b << " " << target << " " << value << endl;*/
                    ans.push_back({a, b});
                }
            }
        }

        cout << ans.size() << endl;
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }
}
