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

// stk is alternating sum up until now
void dfs(int x, const vvi &edges, vll &ans, vb &visited, int depth, stack<ll> &stk, multiset<ll> &mset, const vll &values) {

    visited[x] = true;

    // update psum
    if (depth % 2 == 0) {
        stk.push(stk.top() + values[x]);
    } else {
        stk.push(stk.top() - values[x]);
    }

    // calculate ans for current node
    if (depth % 2 == 0) {
        ll smol = *mset.begin();
        ans[x] = stk.top() - smol;
    } else {
        ll big = *(--mset.end());
        ans[x] = big - stk.top();
    }

    mset.insert(stk.top());
    
    for (auto dest : edges[x]) {
        if (visited[dest])
            continue;
        dfs(dest, edges, ans, visited, depth + 1, stk, mset, values);
    }
    
    mset.erase(mset.find(stk.top()));
    stk.pop();

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll values(n);
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        
        vvi edges(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        vi depth(n);
        vb visited(n, false);
        stack<ll> stk;
        multiset<ll> mset;
        vll ans(n);

        stk.push(0);
        mset.insert(0);
        dfs(0, edges, ans, visited, 0, stk, mset, values);

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
