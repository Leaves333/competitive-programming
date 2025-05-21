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

// make a tree:
// preorder traversal is the given order
// children of each node must be labeled 1, 2, 3 ...

void build_graph(int x, const vi &nums, vvi &edges, vi &color) {

    // find all possible locations to put the new node
    // if there are no good candidates, unwind the stack

    for (int i = 0; i < x; i++) {
        
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {

        int n; cin >> n;
        vi nums(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        vvi edges(n);
        vi color(n);

    }
}
