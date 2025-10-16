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

        // find first zero
        int first_zero = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                first_zero = i;
                break;
            }
        }
        if (first_zero == -1) {
            cout << 1 << " " << s.length() << " " << 1 << " " << 1 << endl;
            continue;
        }

        int ans = 0;
        vector<pair<string, int>> v;
        int dist = s.length() - first_zero;
        for (int i = 0; i < s.length() - dist; i++) {
            string cur = "";
            for (int j = 0; j < dist; j++) {
                if (s[first_zero + j] == s[i + j]) {
                    cur += "0";
                } else {
                    cur += "1";
                }
            }
            v.push_back({cur, i});
        }
        
        sort(v.begin(), v.end());
        int idx = v.back().second;
        cout << 1 << " " << s.length() << " " << idx + 1 << " " << idx + dist << endl;
    }
}
