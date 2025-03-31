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

    int n, k;
    cin >> n >> k;
    vi nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    map<int, int> m;
    int l = 0;
    int best_l = -1, best_r = -2;
    for (int r = 0; r < n; r++) {
        m[nums[r]]++;
        while (m.size() > k) {
            m[nums[l]]--;
            if (m[nums[l]] <= 0)
                m.erase(m.find(nums[l]));
            l++;
        }
        if (r - l > best_r - best_l) {
            best_r = r;
            best_l = l;
        }
    }

    cout << best_l + 1 << " " << best_r + 1 << endl;
}
