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

    int n;
    cin >> n;
    vector<pll> points(n - 2);

    // coords of first and last point
    // should have b=d=0
    ll a, b, c, d;

    // read first point
    cin >> a >> b;

    // read middle points
    for (int i = 0; i < n - 2; i++) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    // read last point
    cin >> c >> d;

    // precompute slopes for each point
    vll left_slopes(n - 2);
    for (int i = 0; i < points.size(); i++)
        left_slopes[i] = (double)points[i].second / (points[i].first - a);
    vll right_slopes(n - 2);
    for (int i = 0; i < points.size(); i++)
        right_slopes[i] = (double)points[i].second / (c - points[i].first);

    vector<pll> max_left(n - 2);
    stack<pll> stk;
    for (int i = 0; i < points.size(); i++) {
        while (!stk.empty() && stk.top().first >= left_slopes[i]) {
            stk.pop();
        }
        if (stk.empty())
            max_left[i] = points[i];
        else
            max_left[i] = points[stk.top().second];
        stk.push({left_slopes[i], i});
    }
    
    while (!stk.empty())
        stk.pop();

    vector<pll> max_right(n - 2);
    for (int i = points.size() - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top().first >= right_slopes[i]) {
            stk.pop();
        }
        if (stk.empty())
            max_right[i] = points[i];
        else
            max_right[i] = points[stk.top().second];
        stk.push({right_slopes[i], i});
    }

    long double ans = 0.0;
    for (int i = 0; i < points.size(); i++) {
        long double left_bound = -1, right_bound = -1;
        if (max_left[i] == points[i]) {
            left_bound = a;
        } else {
            long double slope =
                (double)(points[i].second - max_left[i].second) /
                (points[i].first - max_left[i].first);
            left_bound = points[i].first - (slope * points[i].second);
        }
        if (max_right[i] == points[i]) {
            right_bound = c;
        } else {
            long double slope =
                (double)(points[i].second - max_right[i].second) /
                (max_right[i].first - points[i].first);
            right_bound = points[i].first + (slope * points[i].second);
        }
        cout << "checking point: " << points[i].first << " " << points[i].second
             << endl;
        cout << "max_left: " << max_left[i].first << ", " << max_left[i].second << endl;
        cout << "max_right: " << max_right[i].first << ", " << max_right[i].second << endl;
        cout << "bounds are: " << left_bound << " " << right_bound << endl;
        ans = max(ans, points[i].second * (right_bound - left_bound) / 2);
    }

    cout << setprecision(30) << ans << endl;
}
