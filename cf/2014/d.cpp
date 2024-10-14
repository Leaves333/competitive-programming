#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	/*cout << endl;*/
	for (int t = 0; t < testcases; t++) {

		int n, d, k;
		cin >> n >> d >> k;

		vector<pair<int, int>> jobs;
		int job_starts[n + 1];
		int job_ends[n + 1];

		memset(job_starts, 0, sizeof(job_starts));
		memset(job_ends, 0, sizeof(job_ends));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			jobs.push_back(make_pair(x, y));
			job_starts[x]++;
			job_ends[y]++;
		}

		sort(jobs.begin(), jobs.end());
		int prefix_sum[n + 1];
		prefix_sum[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			prefix_sum[i] = prefix_sum[i - 1] + job_starts[i];
		}

		/*cout << "job_starts: \t";*/
		/*for (int x : job_starts) {*/
		/*	cout << x << " ";*/
		/*}*/
		/*cout << endl;*/
		/**/
		/*cout << "job_ends: \t";*/
		/*for (int x : job_ends) {*/
		/*	cout << x << " ";*/
		/*}*/
		/*cout << endl;*/
		/**/
		/*cout << "prefix_sum: \t";*/
		/*for (int x : prefix_sum) {*/
		/*	cout << x << " ";*/
		/*}*/
		/*cout << endl;*/

		int max_jobs = 0, max_idx = 0, min_jobs = INT_MAX, min_idx = 0;
		int cur_jobs = 0;
		for (int i = 1; i < n + 2 - d; i++) {

			int jobs_during_visit = cur_jobs;
			int last_day = i + d - 1;
			jobs_during_visit += prefix_sum[last_day] - prefix_sum[i - 1];
			
			/*cout << "day " << i << ": " << jobs_during_visit << endl;*/

			if (jobs_during_visit > max_jobs) {
				max_jobs = jobs_during_visit;
				max_idx = i;
			}
			if (jobs_during_visit < min_jobs) {
				min_jobs = jobs_during_visit;
				min_idx = i;
			}

			cur_jobs += job_starts[i];
			cur_jobs -= job_ends[i];

		}

		cout << max_idx << " " << min_idx << endl;
		/*cout << endl;*/

	}

}
