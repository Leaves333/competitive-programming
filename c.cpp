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

struct point {
    ll x, y, dist, idx;
};

bool operator<(const point &lhs, const point &rhs) {
    if (lhs.dist == rhs.dist)
        return lhs.idx < rhs.idx;
    return lhs.dist < rhs.dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pll> points;
        multiset<point> set_pos;
        multiset<point> set_neg;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            points.push_back({x, y});
            set_pos.insert({x, y, x + y, i});
            set_neg.insert({x, y, x - y, i});
        }

        ll sum = 0;
        vector<pii> ans;

        for (int i = 0; i < n / 2; i++) {

            // find best positive
            ll low = set_pos.begin()->dist;
            ll high = set_pos.rbegin()->dist;
            ll mid = (low + high) / 2;

            point boundary_point = point{LLONG_MIN, LLONG_MIN, mid, -1};
            auto it = set_pos.lower_bound(boundary_point);
            point next, prev;

            ll max_dist = LLONG_MIN;
            point max_point, max_bound;

            if (it != set_pos.end()) {
                next = *it;
                if (abs(next.dist - low) > max_dist) {
                    max_dist = abs(next.dist - low);
                    max_point = next;
                    max_bound = *set_pos.begin();
                }
                if (abs(next.dist - high) > max_dist) {
                    max_dist = abs(next.dist - high);
                    max_point = next;
                    max_bound = *set_pos.rbegin();
                }
            }

            if (it != set_pos.begin()) {
                prev = *(--it);
                if (abs(prev.dist - low) > max_dist) {
                    max_dist = abs(prev.dist - low);
                    max_point = prev;
                    max_bound = *set_pos.begin();
                }
                if (abs(prev.dist - high) > max_dist) {
                    max_dist = abs(prev.dist - high);
                    max_point = prev;
                    max_bound = *set_pos.rbegin();
                }
            }

            // do it again for negative....
            low = set_neg.begin()->dist;
            high = set_neg.rbegin()->dist;
            mid = (low + high) / 2;

            boundary_point = point{LLONG_MIN, LLONG_MIN, mid, -1};
            it = set_neg.lower_bound(boundary_point);

            if (it != set_neg.end()) {
                next = *it;
                if (abs(next.dist - low) > max_dist) {
                    max_dist = abs(next.dist - low);
                    max_point = next;
                    max_bound = *set_neg.begin();
                }
                if (abs(next.dist - high) > max_dist) {
                    max_dist = abs(next.dist - high);
                    max_point = next;
                    max_bound = *set_neg.rbegin();
                }
            }

            if (it != set_neg.begin()) {
                prev = *(--it);
                if (abs(prev.dist - low) > max_dist) {
                    max_dist = abs(prev.dist - low);
                    max_point = prev;
                    max_bound = *set_neg.begin();
                }
                if (abs(prev.dist - high) > max_dist) {
                    max_dist = abs(prev.dist - high);
                    max_point = prev;
                    max_bound = *set_neg.rbegin();
                }
            }

            sum += max_dist;
            ans.push_back({max_point.idx, max_bound.idx});
            cout << "found pair: " << max_point.idx + 1 << ", "
                 << max_bound.idx + 1 << endl;
            cout << "adding sum: " << max_dist << endl;

            ll pos_point_dist = max_point.x + max_point.y;
            ll pos_bound_dist = max_bound.x + max_bound.y;
            ll neg_point_dist = max_point.x - max_point.y;
            ll neg_bound_dist = max_bound.x - max_bound.y;

            set_pos.erase(set_pos.find(point{max_point.x, max_point.y,
                                             pos_point_dist, max_point.idx}));
            set_pos.erase(set_pos.find(point{max_bound.x, max_bound.y,
                                             pos_bound_dist, max_bound.idx}));
            set_neg.erase(set_neg.find(point{max_point.x, max_point.y,
                                             neg_point_dist, max_point.idx}));
            set_neg.erase(set_neg.find(point{max_bound.x, max_bound.y,
                                             neg_bound_dist, max_bound.idx}));
        }

        cout << "total sum is " << sum << endl;

        for (auto p : ans) {
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }

    }
}
