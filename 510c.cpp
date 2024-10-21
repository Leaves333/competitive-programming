#include <bits/stdc++.h>
using namespace std;

// init some variables
const string kChars = "abcdefghijklmnopqrstuvwxyz";
map<char, vector<char>> edges;
map<char, vector<char>> parents;

unordered_set<char> visited;
vector<char> ordering;

void dfs(char letter) {

	visited.insert(letter);
	ordering.push_back(letter);

	// do dfs
	for (char dest : edges[letter]) {
		bool all_parents_visited = true;
		for (char parent : parents[letter]) {
			if (!visited.count(parent)) {
				all_parents_visited = false;
				break;
			}
		}

		if (all_parents_visited) {
			dfs(dest);
		}
	}
}

int main() {

	for (char c : kChars) {
		edges[c] = vector<char>();
		parents[c] = vector<char>();
	}

	int n; cin >> n;
	string last_string = "";
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		// generate edge from each pair of strings
		if (last_string != "") {
			int min_length = min(last_string.length(), str.length());
			for (int j = 0; j < min_length; j++) {
				if (last_string[j] != str[j]) {
					char start = last_string[j];
					char end = str[j];

					edges[start].push_back(end);
					parents[end].push_back(start);
					break;
				}
			}
		}

		last_string = str;
	}

	for (char c : kChars) {

		bool all_parents_visited = true;
		for (char parent : parents[c]) {
			if (!visited.count(parent)) {
				all_parents_visited = false;
				break;
			}
		}

		if (all_parents_visited && visited.count(c) == 0) {
			dfs(c);
		}

	}

	if (ordering.size() != kChars.length()) {
		cout << "Impossible" << endl;
		return 0;
	}

	for (char c : ordering) {
		cout << c;
	}
	cout << endl;

}
