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

    int s, n;
    cin >> n >> s;
    vi first(n);
    vi second(n);
    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> second[i];
    }

    s--;
    if (!first[0]) {
        cout << "NO" << endl;
        return 0;
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (first[i]) {
            if (i == s) {
                cout << "YES" << endl;
                return 0;
            }
            if (second[i]) {
                while (idx < i) {
                    idx++;
                    if (second[idx] && idx == s) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
}
