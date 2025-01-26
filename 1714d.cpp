#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        string q; cin >> q;
        int n; cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        vector<pair<pii, int>> ranges; // range, index of matched string
        for (int k = 1; k <= 10; k++) {
            string cur_substr = "";
            for (int i = 0; i < min(k - 1, (int) q.length()); i++) {
                cur_substr += q[i];
            }
            for (int i = k - 1; i < q.length(); i++) {
                cur_substr += q[i];
                for (int j = 0; j < n; j++) {
                    string ss = s[j];
                    if (cur_substr == ss) {
                        /*cout << ss << " matched with " << cur_substr << " at k=" << k << ", i=" << i << endl;*/
                        ranges.push_back(make_pair(make_pair(i - k, i), j + 1));
                    }
                }
                cur_substr.erase(cur_substr.begin());
            }
        }

        sort(all(ranges));

        vector<pii> ans;
        pii best_range;
        if (ranges.size() > 0) {
            best_range = make_pair(ranges[0].second + 1, ranges[0].first.first + 2);
        }

        int idx = 0;
        int cur_dist = -1, max_dist = -1;
        while (idx < ranges.size()) {
            auto r = ranges[idx].first;
            /*cout << "looking at range " << r.first << "," << r.second << " >> " << ranges[idx].second << endl;*/
            if (r.first > cur_dist && r.second > max_dist) {
                /*cout << "too far, adding new range to ans" << endl;*/
                cur_dist = max_dist;
                ans.push_back(best_range);

                // if painting this range didn't unlock any new ranges
                if (r.first > cur_dist) {
                    break;
                }
                best_range = make_pair(ranges[idx].second, r.first + 2);
            }
            if (r.second > max_dist) {
                /*cout << "new best dist" << endl;*/
                best_range = make_pair(ranges[idx].second, r.first + 2);
                max_dist = r.second;
            }
            idx++;
        }
        cur_dist = max_dist;
        ans.push_back(best_range);

        if (max_dist == q.size() - 1 && ans.size() > 0 && ans[0].second == 1) {
            cout << ans.size() << endl;
            for (auto x : ans) {
                cout << x.first << " " << x.second << endl;
            }
        } else {
            cout << -1 << endl;
        }
        /*cout << endl;*/

    }
}
