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

    int n;
    cin >> n;

    vi p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = make_pair(q[i], p[i]);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pii x = v[i];
        cout << q[x.second - 1] << " ";
    }
    cout << endl;

}
