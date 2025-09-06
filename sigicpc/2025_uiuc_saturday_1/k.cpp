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

    ll n;
    cin >> n;
    vll placebo(3);
    vll actual(3);
    ll placebo_count = 0;
    ll actual_count = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool real = (s[0] == 'Y');
        if (real)
            actual_count++;
        else
            placebo_count++;

        for (int j = 1; j < 4; j++) {
            if (real && s[j] == 'Y')
                actual[j - 1]++;
            else if (s[j] == 'Y')
                placebo[j - 1]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        double vac_percent = (double) actual[i] / (double) actual_count;
        double pla_percent = (double) placebo[i] / (double) placebo_count;
        double eff = 1 - (vac_percent / pla_percent);

        // cout << vac_percent << " " << pla_percent << endl;

        if (eff <= 0) {
            cout << "Not Effective" << endl;
        } else {
            cout << eff * 100 << endl;
        }
    }
}
