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
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi a(n), b(n);
        set<int> possible_prices;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            possible_prices.insert(a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            possible_prices.insert(b[i]);
        }

        sort(all(a));
        sort(all(b));

        ll ans = 0;
        int a_idx = 0, b_idx = 0;
        int negative_reviews = 0;
        for (int p : possible_prices) {
            while (a_idx < n && a[a_idx] < p) {
                a_idx++;
                negative_reviews++;
            }
            while (b_idx < n && b[b_idx] < p) {
                b_idx++;
                negative_reviews--;
            }

            ll buyers = n - b_idx;
            /*printf("price: %d, buyers: %d, negative reviews: %d\n", p, (int)buyers, negative_reviews);*/
            if (negative_reviews > k) continue;
            ans = max(ans, p * buyers);
        }

        cout << ans << endl;

    }
}
