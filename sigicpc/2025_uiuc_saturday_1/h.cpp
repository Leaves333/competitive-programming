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

struct peg {
    double left, right;
    int x, y;
    bool drop_point;
    double ev;
    double prob_stuck;
};

void solve(int label, const map<int, double> &legs, map<int, peg> &pegs) {
    peg &cur_peg = pegs[label];

    double ans = 0.0;
    // double prob_left = (cur_peg.left) / (cur_peg.left + cur_peg.right);
    // double prob_right = (cur_peg.right) / (cur_peg.left + cur_peg.right);
    cur_peg.prob_stuck = (1 - cur_peg.left - cur_peg.right);

    if (pegs.count(cur_peg.x)) {
        if (pegs[cur_peg.x].ev < 0) {
            solve(cur_peg.x, legs, pegs);
        }
        ans += pegs[cur_peg.x].ev * cur_peg.left;
        cur_peg.prob_stuck += pegs[cur_peg.x].prob_stuck * cur_peg.left;
    } else {
        ans += legs.at(cur_peg.x) * cur_peg.left;
    }

    if (pegs.count(cur_peg.y)) {
        if (pegs[cur_peg.y].ev < 0) {
            solve(cur_peg.y, legs, pegs);
        }
        ans += pegs[cur_peg.y].ev * cur_peg.right;
        cur_peg.prob_stuck += pegs[cur_peg.y].prob_stuck * cur_peg.right;
    } else {
        ans += legs.at(cur_peg.y) * cur_peg.right;
    }

    // cout << "solving peg " << label << ", ev is " << ans << ", prob stuck is "
    //      << cur_peg.prob_stuck << endl;
    pegs[label].ev = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int l, p;
    cin >> l >> p;

    map<int, double> legs;
    map<int, peg> pegs;
    vb leg_drop_point(l + 1, true);

    // read legs
    for (int i = 1; i <= l; i++) {
        double x;
        cin >> x;
        legs[i] = x;
    }

    // read pegs
    for (int i = l + 1; i <= l + p; i++) {
        double l, r;
        int x, y;
        cin >> l >> r >> x >> y;

        if (pegs.count(x)) {
            pegs[x].drop_point = false;
        } else {
            leg_drop_point[x] = false;
        }
        if (pegs.count(y)) {
            pegs[y].drop_point = false;
        } else {
            leg_drop_point[y] = false;
        }

        pegs[i] = peg{l, r, x, y, true, -1, -1};
    }

    double ans = 0.0;
    for (int i = l + 1; i <= l + p; i++) {
        if (!pegs[i].drop_point)
            continue;
        if (pegs[i].ev < 0)
            solve(i, legs, pegs);
        // cout << "checking peg " << i << ", ans is "
        //      << pegs[i].ev / (1 - pegs[i].prob_stuck) << endl;
        ans = max(ans, pegs[i].ev / (1 - pegs[i].prob_stuck));
    }

    for (int i = 1; i <= l; i++) {
        if (leg_drop_point[i])
            ans = max(ans, legs[i]);
    }

    cout << setprecision(30) << ans << endl;
}
