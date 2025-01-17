#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi questions(m);
        for (int i = 0; i < m; i++) {
            cin >> questions[i];
        }
        set<int> known;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            known.insert(x);
        }

        for (auto x : questions) {
            if (known.size() == n - 1) {
                if (known.count(x)) {
                    cout << "0";
                } else {
                    cout << "1";
                }
            } else if (known.size() < n - 1) {
                cout << "0";
            } else {
                cout << "1";
            }
        }
        cout << endl;
    }
}
