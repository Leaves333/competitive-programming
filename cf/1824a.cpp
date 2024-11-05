#include <bits/stdc++.h>
using namespace std;

int main() {

	int t; cin >> t;
	while (t--) {

		int n, m;
		cin >> n >> m;
		int left_sit = 0, right_sit = 0;
		set<int> occupied_seats;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x == -1) {
				left_sit++;
			} else if (x == -2) {
				right_sit++;
			} else {
				occupied_seats.insert(x);
			}
		}

		int ans = max(min(left_sit + (int) occupied_seats.size(), m), min(right_sit + (int) occupied_seats.size(), m));
		int people_to_left = 0;
		for (auto it = occupied_seats.begin(); it != occupied_seats.end(); it++) {
			int people_to_right = occupied_seats.size() - people_to_left - 1;
			int total_people = 1 + people_to_left + people_to_right;
			total_people += min(m - *it - people_to_right, right_sit);
			total_people += min(*it - people_to_left - 1, left_sit);
			
			ans = max(ans, total_people);
			people_to_left++;
		}

		cout << ans << endl;

	}

}
