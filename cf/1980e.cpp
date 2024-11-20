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
		int n, m;
		cin >> n >> m;

		// grab original matrix
		vector<vi> rows(n, vi(m));
		vector<vi> cols(m, vi(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> rows[i][j];
				cols[j][i] = rows[i][j];
			}
		}

		// hash rows and columns and see if they are the same
		set<vi> hashed_rows;
		set<vi> hashed_cols;
		for (vi row : rows) {
			sort(row.begin(), row.end());
			hashed_rows.insert(row);
		}
		for (vi col : cols) {
			sort(col.begin(), col.end());
			hashed_cols.insert(col);
		}

		// grab second matrix
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> rows[i][j];
				cols[j][i] = rows[i][j];
			}
		}

		bool good = true;
		for (vi row : rows) {
			sort(row.begin(), row.end());
			if (hashed_rows.count(row) == 0) {
				good = false;
				break;
			}
		}
		for (vi col : cols) {
			sort(col.begin(), col.end());
			if (hashed_cols.count(col) == 0) {
				good = false;
				break;
			}
		}

		if (good) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
