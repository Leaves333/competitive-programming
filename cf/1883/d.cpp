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
    multiset<int> left, right;

    while (t--) {
        char op;
        int l, r;
        cin >> op >> l >> r;

        if (op == '+') {
            left.insert(l);
            right.insert(r);
        } else {
            left.erase(left.find(l));
            right.erase(right.find(r));
        }

        if (left.size() > 0 && *(right.begin()) < *(--left.end())) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
