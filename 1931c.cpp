#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int front = 1;
        while (front < n && arr[front] == arr[front - 1]) {
            front++;
        }

        int back = 1;
        while (back < n && arr[n - back] == arr[n - back - 1]) {
            back++;
        }

        if (arr[0] == arr[n - 1]) {
            cout << max(0, n - front - back) << endl;
        } else {
            cout << n - max(front, back) << endl;
        }
    }
}
