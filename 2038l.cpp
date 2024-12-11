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

	int n; cin >> n;

	// target lens = 18, 21, 25
	// each plank has len 60...
	// options:
	// 18 21 25
	// 3  0  0
	// 2  1  0
	// 1  2  0
	// 1  0  1
	// 0  1  1
	// 0  0  2
	
	int boards = 1 + (n - 1) / 2;
	int extra = n % 2;

	int target = (2 * n) - extra;
	boards += 1 + ((target - 1) / 3);

	cout << boards << endl;

}
