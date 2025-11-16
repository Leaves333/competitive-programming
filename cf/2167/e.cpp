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

#define CENTER 1
#define LEFT 2
#define RIGHT 3

struct gap {
    int dist;
    int l, r; // l inclusive, r exclusive
    int pos; // the index corresponding to the dist
    int status; // status of pos, one of { CENTER, LEFT, RIGHT }
};

bool operator<(const gap &l, const gap &r) {
    return l.dist < r.dist;
}

// adjusts the values corresponding to a gap.
// returns -1 on failure.
int decrement(gap *g) {
    if (g->dist == 0)
        return -1;

    if (g->status == CENTER) {
        g->dist--;
        g->status = LEFT;
        g->pos = g->l + g->dist;
    } else if (g->status == LEFT) {
        g->status = RIGHT;
        g->pos = g->r - g->dist;
    } else {
        g->dist--;
        g->status = LEFT;
        g->pos = g->l + g->dist;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vll nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());

        priority_queue<gap> pq;
        for (int i = 0; i < nums.size() - 1; i++) {
            int l = nums[i];
            int r = nums[i + 1];

            gap g;
            g.l = l;
            g.r = r;
            g.dist = (r - l) / 2;
            g.pos = g.l + g.dist;

            if ((r - l) % 2 == 0) {
                g.status = CENTER;
            } else {
                g.status = LEFT;
            }
            pq.push(g);
        }

        int l = 0, r = x;
        vi ans;
        for (int i = 0; i < k; i++) {
            int l_dist = nums.front() - l;
            int r_dist = r - nums.back();
            int g_dist = (pq.empty() ? LLONG_MIN : pq.top().dist);

            if (l < nums.front() && l_dist >= r_dist && l_dist >= g_dist) {
                ans.push_back(l);
                l++;
            } else if (r_dist >= l_dist && r_dist >= g_dist) {
                ans.push_back(r);
                r--;
            } else {
                ans.push_back(pq.top().pos);
                gap g = pq.top();
                pq.pop();
                int ret = decrement(&g);
                if (ret != -1) {
                    pq.push(g);
                }
            }
        }

        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
