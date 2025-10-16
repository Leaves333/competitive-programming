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

        string simp = "";
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                i++;
            } else {
                simp += s[i];
            }
        }

        int l = 0;
        int ans = 0;
        for (int i = 1; i < simp.length(); i++) {
            if (simp[i] == simp[l]) {
                l = i + 1;
                i = l;
            }
        }

        cout << simp << endl;
        cout << ans << endl;
    }
}
