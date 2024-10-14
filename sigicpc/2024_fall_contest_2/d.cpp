#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int a, b, c, x, y, z;
	cin >> a >> c >> b >> x >> z >> y;

	int wins = min(a, z);
	wins += min(b, x);
	wins += min(c, y);


	cout << n - big << " " << wins << endl;
}
