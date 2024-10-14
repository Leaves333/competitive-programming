#include <bits/stdc++.h>
using namespace std;

int main() {

	int testcases; cin >> testcases;
	for (int t = 0; t < testcases; t++) {

		int n, m, h;
		cin >> n >> m >> h;

		unordered_set<int> vertices_with_horses;
		for (int i = 0; i < h; i++) {
			int x; cin >> x;
			vertices_with_horses.insert(x);
		}

		vector<pair<int, int>> edges[n + 1];
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edges[u].push_back(make_pair(v, w));
			edges[v].push_back(make_pair(u, w));
		}

		// dijkstra from 1
		long long distance_from_1[n + 1];
		long long distance_from_1_with_horse[n + 1];
		for (int i = 0; i < n + 1; i++) {
			distance_from_1[i] = LONG_LONG_MAX;
			distance_from_1_with_horse[i] = LONG_LONG_MAX;
		}
		distance_from_1[1] = 0;

		priority_queue<pair<long long, pair<int, bool>>, vector<pair<long long, pair<int, bool>>>, greater<pair<long long, pair<int, bool>>>> q; // distance, current node, do they have a horse
		q.push(make_pair(0, make_pair(1, false)));
		while (q.size() > 0) {

			auto pair = q.top();
			q.pop();
			
			long long distance = pair.first;
			int cur = pair.second.first;
			bool has_horse = pair.second.second;
			if (vertices_with_horses.count(cur) > 0) {
				has_horse = true;
			}

			for (auto edge : edges[cur]) {

				int dist_to_neighbor = edge.second;
				int destination = edge.first;

				long long new_distance = distance;
				if (has_horse) {
					new_distance += dist_to_neighbor / 2;
					if (new_distance < distance_from_1_with_horse[destination]) {
						distance_from_1_with_horse[destination] = new_distance;
						q.push(make_pair(new_distance, make_pair(destination, has_horse)));
					}
				} else {
					new_distance += dist_to_neighbor;
					if (new_distance < distance_from_1[destination] && new_distance < distance_from_1_with_horse[destination]) {
						distance_from_1[destination] = new_distance;
						q.push(make_pair(new_distance, make_pair(destination, has_horse)));
					}
				}

			}
		}

		// dijkstra from n
		long long distance_from_n[n + 1];
		long long distance_from_n_with_horse[n + 1];
		for (int i = 0; i < n + 1; i++) {
			distance_from_n[i] = LONG_LONG_MAX;
			distance_from_n_with_horse[i] = LONG_LONG_MAX;
		}
		distance_from_n[n] = 0;

		// the queue should be empty here...
		q.push(make_pair(0, make_pair(n, false)));
		while (q.size() > 0) {

			auto pair = q.top();
			q.pop();
			
			long long distance = pair.first;
			int cur = pair.second.first;
			bool has_horse = pair.second.second;
			if (vertices_with_horses.count(cur) > 0) {
				has_horse = true;
			}

			for (auto edge : edges[cur]) {

				int dist_to_neighbor = edge.second;
				int destination = edge.first;

				long long new_distance = distance;
				if (has_horse) {
					new_distance += dist_to_neighbor / 2;
					if (new_distance < distance_from_n_with_horse[destination]) {
						distance_from_n_with_horse[destination] = new_distance;
						q.push(make_pair(new_distance, make_pair(destination, has_horse)));
					}
				} else {
					new_distance += dist_to_neighbor;
					if (new_distance < distance_from_n[destination] && new_distance < distance_from_n_with_horse[destination]) {
						distance_from_n[destination] = new_distance;
						q.push(make_pair(new_distance, make_pair(destination, has_horse)));
					}
				}

			}
		}

		/*cout << "distance from 1:" << endl;*/
		/*for (int i = 1; i < n + 1; i++) {*/
		/*	cout << "\t" << i << ": " << distance_from_1[i] << endl; */
		/*}*/
		/*cout << endl;*/
		/**/
		/*cout << "distance from n:" << endl;*/
		/*for (int i = 1; i < n + 1; i++) {*/
		/*	cout << "\t" << i << ": " << distance_from_n[i] << endl; */
		/*}*/
		/*cout << endl;*/

		// check for the best location
		long long best_time = LONG_LONG_MAX;
		for (int i = 1; i < n + 1; i++) {
			long long from_1 = min(distance_from_1[i], distance_from_1_with_horse[i]);
			long long from_n = min(distance_from_n[i], distance_from_n_with_horse[i]);
			long long time_needed = max(from_1, from_n);
			if (time_needed < best_time) {
				best_time = time_needed;
			}
		}

		if (best_time == LONG_LONG_MAX) {
			cout << -1 << endl;
		} else {
			cout << best_time << endl;
		}

		/*cout << endl;*/

	}

}
