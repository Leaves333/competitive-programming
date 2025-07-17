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
        int remaining_heroes = 0;
        vi cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
            if (cards[i] == 0)
                remaining_heroes++;
        }

        multiset<int> s;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (cards[i] == 0) {
                remaining_heroes--;
                if (!s.empty()) {
                    ans += *s.rbegin();
                    s.erase(--s.end());
                }
            } else {
                s.insert(cards[i]);
            }

            while (s.size() > remaining_heroes) {
                s.erase(s.begin());
            }
        }
        cout << ans << endl;
    }
}
