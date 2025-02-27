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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vll cols(n);
    for (int i = 0; i < n; i++) {
        cin >> cols[i];
    }

    vll psum_left_to_right(n + 2);
    vll psum_right_to_left(n + 2);
    for (int i = 0; i < n - 1; i++) {
        psum_left_to_right[i + 1] = psum_left_to_right[i] + ((cols[i] > cols[i + 1]) ? cols[i] - cols[i + 1] : 0);
    }
    for (int i = n - 1; i > 0; i--) {
        psum_right_to_left[i - 1] = psum_right_to_left[i] + ((cols[i] > cols[i - 1]) ? cols[i] - cols[i - 1] : 0);
    }

    while (m--) {
        int s, t;
        cin >> s >> t;
        if (s > t) {
            cout << psum_right_to_left[t-1] - psum_right_to_left[s-1] << endl;
        } else {
            cout << psum_left_to_right[t-1] - psum_left_to_right[s-1] << endl;
        }
    }
}
