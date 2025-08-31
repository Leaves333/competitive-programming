#include <algorithm>
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

    int n; cin >> n;
    vi greater;
    vi less;
    vi positions;
    for (int i = 0; i < n; i++) {
        char c; int x;
        cin >> c >> x;
        if (c == 'G')
            greater.push_back(x);
        else
            less.push_back(x);
        positions.push_back(x);
    }

    sort(greater.begin(), greater.end());
    sort(less.begin(), less.end());
    sort(positions.begin(), positions.end());

    int greater_idx = 0;
    int less_idx = 0;
    int min_liars = INT_MAX;
    for (int p : positions) {
        while (greater_idx < greater.size() && greater[greater_idx] <= p) {
            greater_idx++;
        }
        while (less_idx < less.size() && less[less_idx] < p) {
            less_idx++;
        }

        int num_liars = (greater.size() - greater_idx) + less_idx;
        min_liars = min(min_liars, num_liars);
    }

    cout << min_liars << endl;
}
