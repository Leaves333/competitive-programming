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

    int n, q;
    cin >> n >> q;
    vll prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    sort(prices.begin(), prices.end(), std::greater<int>());
    // 5 5 3 2 1

    vll psum(1);
    for (int i = 0; i < n; i++) {
        psum.push_back(psum[psum.size() - 1] + prices[i]);
    }
    // 0 5 10 13 15 16

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << psum[x] - psum[x - y] << endl;
    }
}
