#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct SegmentTree {

    vll nums;
    vector<pll> max_tree;      // max value of segment, index

    int l(int x) { return x * 2; }

    int r(int x) { return x * 2 + 1; }

    void build(vll &a) {
        nums = a;
        max_tree.resize(nums.size() * 4);
        build(1, 0, nums.size() - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            max_tree[v] = {nums[tl], tl};
        } else {
            int tm = (tl + tr) / 2;
            build(l(v), tl, tm);
            build(r(v), tm + 1, tr);

            if (max_tree[l(v)].first == max_tree[r(v)].first) {
                max_tree[v] = max_tree[l(v)];
            } else if (max_tree[l(v)].first > max_tree[r(v)].first) {
                max_tree[v] = max_tree[l(v)];
            } else {
                max_tree[v] = max_tree[r(v)];
            }
        }
    }

    // returns pair of {max_value, vector of indices}
    pll query(int l, int r) { return query(1, 0, nums.size() - 1, l, r); }

    pll query(int v, int tl, int tr, int ll, int rr) {
        if (ll > rr)
            return {-1, -1};
        if (ll == tl && rr == tr) {
            return max_tree[v];
        }
        int tm = (tl + tr) / 2;

        auto left = query(l(v), tl, tm, ll, min(rr, tm));
        auto right = query(r(v), tm + 1, tr, max(ll, tm + 1), rr);
        if(left.first > right.first){
            return left;
        }
        else if(left.first < right.first){
            return right;
        }
        return left; // default to left if in doubt
    }
};

int main() {

    int n;
    cin>>n;
    vll nums(n);
    vll prefix_sum(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }
    SegmentTree segtree;
    segtree.build(nums);
    
    pii bestsol = {0, n-1};
    vector<pii> solutions {{0, n-1}};
    for(int i = 0; i < 100; i++){
        vector<pii> temp;
        for(pii el : solutions){
            pll q = segtree.query(el.first, el.second);
            ll maxval = q.first;
            int start = el.first;
            while(segtree.query(start, el.second).first == maxval && el.second - start >= 2){
                // if(q.second - start > 2){
                //     if(n != 5){
                //         cout<<"1"<<endl;
                //     }
                //     temp.push_back({start, q.second - 1});
                //     if(prefix_sum[q.second] - prefix_sum[start] <= 2 * segtree.query(start, q.second-1).first) continue;
                //
                //     if(q.second -1 - start < bestsol.second - bestsol.first){
                //         bestsol = {start, q.second - 1};
                //     }
                //     else if(q.second - 1 - start == bestsol.second - bestsol.first && start < bestsol.first){
                //         bestsol = {start, q.second - 1};
                //     }
                // }
                // start = q.second + 1;
                // if(start + 2 > el.second){
                //     break;
                // }
                // q = segtree.query(start, el.second);
            }
            if(el.second - start > 1){
                if(n != 5){
                    cout<<"2"<<endl;
                }

                temp.push_back({start, el.second});
                if(prefix_sum[el.second+1] - prefix_sum[start] <= 2 * segtree.query(start, el.second).first) continue;

                if(el.second - start < bestsol.second - bestsol.first){
                    bestsol = {start, el.second};
                }
                else if(el.second - start == bestsol.second - bestsol.first && start < bestsol.first){
                    bestsol = {start, el.second};
                }

                // update bestsol
            }
        }
        solutions = temp;
        temp = {};
    }
    cout<<bestsol.first+1<<" "<<bestsol.second+1<<"\n";
}
