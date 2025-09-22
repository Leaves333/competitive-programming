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

struct SegmentTree {

    int n;      // size of segtree
    int height; // height of segtree
    vll nums;   // stores the base values
    vll tree;   // stores the actual tree

    // return left child
    int l(int p) { return p << 1; }

    // return right child
    int r(int p) { return (p << 1) + 1; }

    // operation we want to do
    ll func(ll a, ll b, int depth) {
        if (depth % 2 == 1)
            return a | b;
        else
            return a ^ b;
    }

    // recursive function to build the segtree
    void build(int p, int tl, int tr, int depth) {
        if (tl == tr) {
            tree[p] = nums[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(l(p), tl, tm, depth - 1);
            build(r(p), tm + 1, tr, depth - 1);
            tree[p] = func(tree[l(p)], tree[r(p)], depth);
        }
    }

    // init segtree with an array
    void init_segtree(const vll &v, int depth) {
        nums = v;
        height = depth;
        n = nums.size();
        tree.resize(4 * n);

        // build segtree from root node
        build(1, 0, n - 1, height);
    }

    // does a range query
    ll query(int p, int tl, int tr, int left, int right, int depth) {

        // this case should never happen. bad query
        if (left > right)
            return 0;

        // exactly the right segment
        if (left == tl && right == tr)
            return tree[p];

        int tm = (tl + tr) / 2;
        return func(
            query(l(p), tl, tm, left, min(tm, right), depth - 1),
            query(r(p), tm + 1, tr, max(left, tm + 1), right, depth - 1),
            depth);
    }

    ll query(int left, int right) {
        return query(1, 0, n - 1, left, right, height);
    }

    // updates a single node
    void update(int p, int tl, int tr, int pos, ll new_val, int depth) {
        if (tl == tr) {
            tree[p] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(l(p), tl, tm, pos, new_val, depth - 1);
            else
                update(r(p), tm + 1, tr, pos, new_val, depth - 1);
            tree[p] = func(tree[l(p)], tree[r(p)], depth);
        }
    }

    void update(int pos, ll new_val) {
        update(1, 0, n - 1, pos, new_val, height);
    }

    void print() {
        cout << "printing segtree:" << endl;
        cout << "tree is: ";
        for (auto x : tree) {
            cout << x << " ";
        }
        cout << endl << endl;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    ll amt = pow(2, n);

    vll nums(amt);
    for (int i = 0; i < amt; i++) {
        cin >> nums[i];
    }

    SegmentTree segtree;
    segtree.init_segtree(nums, n);

    while (m--) {
        ll p, b;
        cin >> p >> b;
        segtree.update(p - 1, b);
        cout << segtree.tree[1] << endl;
    }
}
