#include <iomanip>
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

    int r, y, d, w;
    cin >> r >> y >> d >> w;

    double growth = 1 + (0.01) * r;
    double ans = 0.0;

    int total_years = y + 1;
    for (int deposit_years = 1; deposit_years <= total_years; deposit_years++) {
        for (int withdrawl_years = 1; withdrawl_years <= total_years - deposit_years; withdrawl_years++) {
            // simulate.
            cout << deposit_years + withdrawl_years << endl;
        }
    }

    cout << setprecision(30) << ans << endl;
}
