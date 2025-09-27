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

    int n;
    cin >> n;
    vector<pll> points;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({ x * 2, y * 2 });
    }

    if (n % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }

    pll midpoint = {-1, -1};
    bool good = true;
    for (int i = 0; i < n / 2; i++) {
        pll a = points[i], b = points[i + n / 2];
        ll x = (a.first + b.first) / 2;
        ll y = (a.second + b.second) / 2;
        if (midpoint.first == -1) {
            midpoint.first = x;
            midpoint.second = y;
        } else {
            if (x != midpoint.first) {
                good = false;
                break;
            }
            if (y != midpoint.second) {
                good = false;
                break;
            }
        }
    }

    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
