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

    int t;
    cin >> t;
    while (t--) {
        ll k, d;
        cin >> d >> k;

        ll smol = floor((double) d / sqrt(2));
        ll x = (smol / k) * k, y = (smol / k) * k;
        bool ash = true;
        while ((x * x) + (y * y) <= d * d) {
            if (ash)
                x += k;
            else
                y += k;
            ash = !ash;
        }

        if (ash) {
            cout << "Ashish" << endl;
        } else {
            cout << "Utkarsh" << endl;
        }
    }
}
