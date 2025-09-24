#include <cstdlib>
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

struct node {
    ll val;
    node *left, *right;
};

node *insert(node *cur, ll val) {
    if (cur == NULL) {
        cur = new node();
        cur->left = NULL;
        cur->right = NULL;
        cur->val = val;
    } else if (cur->val > val) {
        cur->left = insert(cur->left, val);
    } else {
        cur->right = insert(cur->right, val);
    }
    return cur;
}

void dfs(node *cur, string &str) {
    if (cur == NULL)
        return;
    str += "(";
    dfs(cur->left, str);
    str += "0";
    dfs(cur->right, str);
    str += ")";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    set<string> s;

    for (int i = 0; i < n; i++) {
        node *head = NULL;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (head == NULL) {
                head = new node();
                head->left = NULL;
                head->right = NULL;
                head->val = x;
            } else {
                insert(head, x);
            }
        }

        string str = "";
        dfs(head, str);
        s.insert(str);
    }

    cout << s.size() << endl;
}
