#include <algorithm>
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

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vi nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    sort(nums.begin(), nums.end());

    a = nums[0];
    b = nums[1];
    c = nums[2];
    int i = 0;
    while (n >= nums[i % 3]) {
        n -= nums[i % 3];
        i++;
    }
    cout << i << endl;
    
}
