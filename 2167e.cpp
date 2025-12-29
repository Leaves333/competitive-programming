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

vector<pll> merge_intervals(const vector<pll> &intervals) {
    vector<pll> ans;
    for (int i = 0; i < intervals.size(); i++) {
        pll cur = intervals[i];
        if (ans.size() == 0) {
            ans.push_back(cur);
        } else {
            if (cur.first <= ans.back().second) {
                ans.back().second = max(ans.back().second, cur.second);
            } else {
                ans.push_back(cur);
            }
        }
    }
    return ans;
}

bool valid(int m, ll k, ll x, const vll &pos) {

    // printf("valid: %d, %lld, %lld\n", m, k, x);
    vector<pll> intervals;
    for (ll a : pos) {
        intervals.push_back({a - m + 1, a + m - 1});
    }

    // cout << "intervals for before merge: " << endl;
    // for (auto i : intervals) {
    //     cout << i.first << "-" << i.second << endl;
    // }
    // cout << endl;
    //
    intervals = merge_intervals(intervals);

    // cout << "intervals for valid: " << endl;
    // for (auto i : intervals) {
    //     cout << i.first << "-" << i.second << endl;
    // }
    // cout << endl;
    //
    ll count = 0;
    ll last_pos = 0;
    for (pll interval : intervals) {
        count += max(0ll, interval.first - last_pos);
        last_pos = interval.second;
    }
    count += max(0ll, x - last_pos);

    // cout << "valid counted " << count << "/" << k << endl;
    return count >= k;
}

vll generate(int m, ll k, ll x, const vll &pos) {
    vector<pll> intervals;
    if (m != 0) { // edge case, if m=0 then no intervals are blocketd
        for (ll x : pos) {
            intervals.push_back({x - m + 1, x + m - 1});
        }
    }
    intervals = merge_intervals(intervals);

    // cout << "intervals for generate: " << endl;
    // for (auto i : intervals) {
    //     cout << i.first << "-" << i.second << endl;
    // }
    // cout << endl;
    //
    vll ans;
    int p = 0;
    for (int i = 0; i < intervals.size(); i++) {
        while (ans.size() < k) {
            if (p >= intervals[i].first) {
                break;
            }
            ans.push_back(p);
            p++;
        }
        p = intervals[i].second + 1;
    }
    while (ans.size() < k) {
        ans.push_back(p);
        p++;
    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;

        vll pos(n);
        for (int i = 0; i < n; i++) {
            cin >> pos[i];
        }
        sort(pos.begin(), pos.end());

        // binary search for largest value of m that makes true
        int low = 0, high = x;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            // printf("bsearch: \tlow: %d\tmid: %d\thigh: %d\n", low, mid, high);
            if (valid(mid, k, x, pos)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        // cout << low << endl;
        vll ans = generate(low, k, x, pos);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
