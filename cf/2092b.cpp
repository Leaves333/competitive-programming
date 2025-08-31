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
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int count_one = 0, count_two = 0;
        for (int i = 0; i < n; i += 2) {
            count_one += (a[i] == '1');
            count_two += (b[i] == '1');
        }
        for (int i = 1; i < n; i += 2) {
            count_two += (a[i] == '1');
            count_one += (b[i] == '1');
        }

        if (count_one <= (n / 2) && count_two <= (n + 1) / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
