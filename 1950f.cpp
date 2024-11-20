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
		int a, b, c;
		cin >> a >> b >> c;

		if (c != a + 1) {
			cout << -1 << endl;
			continue;
		}

		if (a + b + c == 1) {
			cout << 0 << endl;
			continue;
		}

		int leaves_cur = 1;
		int leaves_next = 0;
		int depth = 1;

		for (int i = 0; i < a; i++) {
			if (leaves_cur == 0) {
				leaves_cur = leaves_next;
				leaves_next = 0;
				depth++;
			}
			leaves_cur -= 1;
			leaves_next += 2;
		}

		for (int i = 0; i < b; i++) {
			if (leaves_cur == 0) {
				leaves_cur = leaves_next;
				leaves_next = 0;
				depth++;
			}
			leaves_cur -= 1;
			leaves_next += 1;
		}

		cout << depth << endl;
	}
}
