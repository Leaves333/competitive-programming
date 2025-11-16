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

    double t, p;
    cin >> t >> p;
    double used = 100 - p;
    used += max(0.0, 20 - p);

    double persec = used / t;
    double remaining = p + min(20.0, p);
    cout << setprecision(15) << remaining / persec << endl;
}
