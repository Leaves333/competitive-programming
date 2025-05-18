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

    int t; cin >> t;
    while (t--) {
        int q; cin >> q;

        deque<ll> nums;
        deque<ll> reverse;
        
        ll sum = 0; // sum of whole array
        ll normal_ans = 0; // ans for forwards
        ll reverse_ans = 0; // ans for backwards

        while (q--) {

            int op, k; cin >> op;
            if (op == 1) {
                ll back = nums.back();
                nums.pop_back();
                nums.push_front(back);
                normal_ans += sum;
                normal_ans -= back * nums.size();

                ll front = reverse.front();
                reverse.pop_front();
                reverse.push_back(front);
                reverse_ans -= sum;
                reverse_ans += front * reverse.size();
            } else if (op == 2) {
                swap(nums, reverse);
                swap(normal_ans, reverse_ans);
            } else if (op == 3) {
                cin >> k;

                nums.push_back(k);
                normal_ans += k * nums.size();

                reverse.push_front(k);
                reverse_ans += sum;
                reverse_ans += k;
                
                sum += k;
            }

            cout << normal_ans << endl;

        }
    }
}
