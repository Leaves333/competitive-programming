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

    const int N = 100001;
    vb is_prime(N, true);
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i + i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi nums(n);
        ll sum = 0;
        int odd_idx = -1;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
            if (nums[i] % 2 == 1)
                odd_idx = i;
        }
        odd_idx++;

        if (is_prime[sum]) {
            cout << n - 1 << endl;
            for (int i = 1; i <= n; i++) {
                if (i != odd_idx)
                    cout << i << " ";
            }
            cout << endl;
        } else {
            cout << n << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
