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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 1;

        int cur = 1;
        if (c == a + b + b)
            cur++;
        if (d == c + a + b)
            cur++;
        ans = max(ans, cur);

        cur = 1;
        if (a + b == c - b)
            cur++;
        if (c - b + c == d)
            cur++;
        ans = max(ans, cur);

        cur = 1;
        if (d - c == a + b)
            cur++;
        if (b + d - c == c)
            cur++;
        ans = max(ans, cur);
        
        cout << ans << endl;
    }
}
