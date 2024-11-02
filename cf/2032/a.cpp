#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int lights_on = 0;
		for (int i = 0; i < 2 * n; i++) {
			int x; cin >> x;
			if (x) {
				lights_on++;
			}
		}

		int min_lights = lights_on % 2;
		int max_lights = lights_on;
		if (lights_on > n) {
			max_lights -= 2 * (lights_on - n);
		}
		cout << min_lights << " " << max_lights << endl;
	}
}
