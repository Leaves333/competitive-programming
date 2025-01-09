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
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        string ans = "Unique";
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == '#' && b[i] == '#') {
                continue;
            } else if (a[i] == '#' && b[i] == '.') {
                if (b[i + 1] == '#') {
                    ans = "None";
                    break;
                }
                b[i] = '#';
                b[i + 1] = '#';
            } else if (a[i] == '.' && b[i] == '#') {
                if (a[i + 1] == '#') {
                    ans = "None";
                    break;
                }
                a[i] = '#';
                a[i + 1] = '#';
            } else {
                if (a[i + 1] == '.' && b[i + 1] == '.') {
                    ans = "Multiple";
                }
            }
        }

        if (a[n - 1] == b[n - 1]) {
            cout << ans << endl;
        } else {
            cout << "None" << endl;
        }
    }
}
