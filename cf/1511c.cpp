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

    int n, q;
    cin >> n >> q;

    vi nums(n), queries(q);
    vi pos(51, -1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (pos[nums[i]] == -1)
            pos[nums[i]] = i + 1;
    }

    while (q--) {
        int q; cin >> q;
        cout << pos[q] << " ";
        for (int i = 0; i < 51; i++) {
            if (i == q)
                continue;
            if (pos[i] <= pos[q] && pos[i] != -1)
                pos[i]++;
        }
        pos[q] = 1;
    }
    cout << endl;

}
