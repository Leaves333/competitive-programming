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

void transpose(int i, int j, vi &a, vi &b, vi &idx) {
    swap(idx[a[i]], idx[a[j]]);
    swap(a[i], a[j]);
    swap(b[i], b[j]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }

        vi match(n), idx(n);
        for (int i = 0; i < n; i++) {
            match[a[i]] = b[i];
            idx[a[i]] = i;
        }

        int middle = -1;
        bool bad_matches = false;
        for (int i = 0; i < n; i++) {
            if (i == match[i]) {
                if (middle != -1) {
                    bad_matches = true;
                    break;
                }
                middle = idx[i];
                continue;
            } else if (i == match[match[i]]) {
                continue;
            }
            bad_matches = true;
            break;
        }

        if (bad_matches) {
            cout << -1 << endl;
            continue;
        } else if (n % 2 == 0 && middle != -1) {
            cout << -1 << endl;
            continue;
        } else {
            vector<pii> swaps;
            if (n % 2 == 1 && middle != n / 2) {
                swaps.push_back({middle, n / 2});
                transpose(middle, n / 2, a, b, idx);
            }
            for (int i = 0; i < n / 2; i++) {
                if (a[i] != b[n - i - 1]) {
                    swaps.push_back({idx[b[i]], n - i - 1});
                    transpose(idx[b[i]], n - i - 1, a, b, idx);
                }
            }

            cout << swaps.size() << endl;
            for (auto p : swaps) {
                cout << p.first + 1 << " " << p.second + 1 << endl;
            }

        }
    }
}
