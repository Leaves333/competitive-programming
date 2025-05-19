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
        int n;
        string s;
        cin >> n >> s;

        if (n == 2) {
            cout << stoi(s) << endl;
        } else if (s == "101") {
            cout << 1 << endl;
        } else {

            // pick which one is two long
            ll ans = LLONG_MAX;
            /*cout << "checking: " << s << endl;*/
            for (int k = 0; k < n - 1; k++) {

                ll cur = 0;

                vector<string> splits;
                for (int i = 0; i < k; i++) {
                    splits.push_back(string(1, s[i]));
                }
                splits.push_back(s.substr(k, 2));
                for (int i = k + 2; i < n; i++) {
                    splits.push_back(string(1, s[i]));
                }

                /*cout << "splits: ";*/
                /*for (string x : splits) {*/
                /*    cout << x << " ";*/
                /*}*/
                /*cout << endl;*/
                /**/
                for (string split : splits) {
                    if (split == "0") {
                        cur = 0;
                        break;
                    } else if (split != "1" && split != "01") {
                        cur += stoi(split);
                    }
                }
                
                ans = min(ans, cur);

            }

            cout << ans << endl;

        }

    }
}
