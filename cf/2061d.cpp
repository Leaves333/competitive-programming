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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<int> a, b;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push(x);
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            b.push(x);
        }

        int target_operations = n - m;
        int cur_operations = 0;

        while (cur_operations <= target_operations && b.size() > 0 && a.size() > 0) {

            int a_top = a.top();
            int b_top = b.top();

            if (b_top == a_top) {
                a.pop();
                b.pop();
                continue;
            }

            b.pop();
            b.push(b_top / 2);
            b.push(b_top / 2 + (b_top % 2));
            cur_operations++;

        }

        if (a.size() == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
