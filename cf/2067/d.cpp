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
        int n;
        cin >> n;
        vi x(n);
        int one_idx = -1, n_idx = -1;
        bool is_permutation = true;
        vb seen(n + 1, false);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            if (x[i] == 1)
                one_idx = i + 1;
            else if (x[i] == n)
                n_idx = i + 1;
            if (seen[x[i]])
                is_permutation = false;
            seen[x[i]] = true;
        }

        if (is_permutation) {
            ll a, b;
            cout << "? " << one_idx << " " << n_idx << endl;
            cin >> a;
            cout << "? " << n_idx << " " << one_idx << endl;
            cin >> b;

            if (a != b || a < n - 1)
                cout << "! A" << endl;
            else
                cout << "! B" << endl;
        } else {
            int first_nonexistent = -1;
            for (int i = 1; i <= n; i++) {
                if (!seen[i]) {
                    first_nonexistent = i;
                    break;
                }
            }

            ll a, b;
            if (first_nonexistent == 1) {
                cout << "? 1 2" << endl;
                cin >> a;
                cout << "? 2 1" << endl;
                cin >> b;
            } else {
                cout << "? 1 " << first_nonexistent << endl;
                cin >> a;
                cout << "? " << first_nonexistent << " 1" << endl;
                cin >> b;
            }
            if (a == 0 || b == 0 || a != b)
                cout << "! A" << endl;
            else
                cout << "! B" << endl;
        }

    }
}
