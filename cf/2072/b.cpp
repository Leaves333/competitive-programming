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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        ll dash = 0, score = 0;
        for (char c : s) {
            if (c == '-')
                dash++;
            else
                score++;
        }

        cout << (dash / 2) * score * (dash - (dash / 2)) << endl;
    }
}
