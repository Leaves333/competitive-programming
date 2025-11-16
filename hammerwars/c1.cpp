#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;

int main() {
    int n; cin >> n;
    vll nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vll ans;
    for (int k = 1; k <= n; k++) {
        bool good = true;
        for (int i = 0; i + k < n; i++) {
            if (nums[i+k] < nums[i]) {
                good = false;
                break;
            }
        }
        if (good) {
            ans.push_back(k);
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
}
