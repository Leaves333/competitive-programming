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
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;

        vi a_freq(26), b_freq(26);
        for (int i = 0; i < n; i++) {
            a_freq[a[i] - 'a']++;
            b_freq[b[i] - 'a']++;
        }

        bool good = true;
        for (int i = 0; i < 25; i++) {
            if (a_freq[i] < b_freq[i]) {
                good = false;
                break;
            }
            int diff = a_freq[i] - b_freq[i];
            if (diff % k != 0) {
                good = false;
                break;
            }
            a_freq[i] -= diff;
            a_freq[i + 1] += diff;
        }
        if (a_freq[25] != b_freq[25])
            good = false;

        if (good)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
