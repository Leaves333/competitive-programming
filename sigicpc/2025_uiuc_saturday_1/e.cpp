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

    int n, p, s;
    cin >> n >> p >> s;

    while (s--) {
        int m;
        cin >> m;
        bool seen = false;
        while (m--) {
            int x; cin >> x;
            if (x == p)
                seen = true;
        }

        if (seen)
            cout << "KEEP" << endl;
        else
            cout << "REMOVE" << endl;
    }
}
