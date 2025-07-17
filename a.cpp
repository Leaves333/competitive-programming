#include <cctype>
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
        string s; cin >> s;

        int i = 0;
        vb flags(4);
        while (i < n) {
            char c = s[i];
            if (isupper(c))
                c = tolower(c);
            if (c != 'm')
                break;
            i++;
            flags[0] = true;
        }
        while (i < n) {
            char c = s[i];
            if (isupper(c))
                c = tolower(c);
            if (c != 'e')
                break;
            i++;
            flags[1] = true;
        }
        while (i < n) {
            char c = s[i];
            if (isupper(c))
                c = tolower(c);
            if (c != 'o')
                break;
            i++;
            flags[2] = true;
        }
        while (i < n) {
            char c = s[i];
            if (isupper(c))
                c = tolower(c);
            if (c != 'w')
                break;
            i++;
            flags[3] = true;
        }

        bool all_flags = true;
        for (auto f : flags) {
            all_flags &= f;
        }
        cout << (i == n && all_flags ? "YES" : "NO") << endl;
    }
}
