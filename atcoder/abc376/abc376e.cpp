#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {

		int n, k;
		cin >> n >> k;

		int A[n];
		int B[n];
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> B[i];
		}

		vector<pair<int, int>> sorted;
		for (int i = 0; i < n; i++) {
			sorted.push_back(make_pair(A[i], B[i]));
		}
		sort(sorted.begin(), sorted.end());


		priority_queue<int> heap;
		long long sum = 0;
		for (int i = 0; i < k - 1; i++) {
			int x = sorted[i].second;
			heap.push(x);
			sum += x;
		}

		long long ans = LLONG_MAX;
		for (int i = k - 1; i < n; i++) {
			int x = sorted[i].second;
			heap.push(x);
			sum += x;

			ans = min(ans, sorted[i].first * sum);

			sum -= heap.top();
			heap.pop();
		}

		cout << ans << endl;

	}

}
