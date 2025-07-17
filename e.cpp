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
        string s, t;
        cin >> s >> t;

        // find middle unswappable section...
        // solve???

        map<char, int> s_freq;
        map<char, int> t_freq;
        int high = k, low = n - k;

        // cout << "0 " << low << " " << high << " " << n << endl;

        bool good = true;
        for (int i = max(0, low); i < min(n, high); i++) {
            // cout << "matching " << i << endl;
            if (s[i] != t[i]) {
                good = false;
            }
        }

        for (int i = 0; i < low; i++) {
            // cout << "counting " << i << endl;
            s_freq[s[i]]++;
            t_freq[t[i]]++;
        }

        for (int i = max(low, high); i < n; i++) {
            // cout << "counting " << i << endl;
            s_freq[s[i]]++;
            t_freq[t[i]]++;
        }

        for (auto &[key, val] : s_freq) {
            if (t_freq[key] != val) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
