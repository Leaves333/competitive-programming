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

    const int N = 20;
    for (int r = 1; r <= N; r++) {
        ll ans = 0;
        for (int x = -r; x <= r; x++) {
            for (int y = -r; y <= r; y++) {
                if ((x * x) + (y * y) <= r * r) {
                    ans++;
                }
            }
        }
        cout << r << " -> " << ans << endl;
    }
}
