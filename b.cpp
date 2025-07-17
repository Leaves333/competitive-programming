#include <cmath>
#include <queue>
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
        int n, k;
        cin >> n >> k;
        string s; cin >> s;

        map<char, int> freq;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            int smol = min(freq['a' + i], freq['A' + i]);
            int remainder = max(freq['a' + i] - smol, freq['A' + i] - smol);
            int bonus = min(remainder / 2, k);
            k -= bonus;
            ans += smol + bonus;
        }

        cout << ans << endl;
    }
}
