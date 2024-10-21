#include <bits/stdc++.h>
using namespace std;

struct Request {
	int id;
	int cost;
	int people;

	Request(int i, int c, int p) {
		id = i;
		cost = c;
		people = p;
	}
};

struct sort_by_cost
{
    inline bool operator() (const Request& struct1, const Request& struct2)
    {
        return (struct1.cost > struct2.cost);
    }
};

struct Table {
	int id;
	int size;
	
	Table(int i, int s) {
		id = i;
		size = s;
	}
};

struct sort_by_size
{
    inline bool operator() (const Table& struct1, const Table& struct2)
    {
        return (struct1.size < struct2.size);
    }
};

int main() {

	int n; cin >> n;
	vector<Request> requests;
	for (int i = 0; i < n; i++) {
		int c, p;
		cin >> c >> p;
		requests.push_back(Request(i + 1, p, c));
	}
	sort(requests.begin(), requests.end(), sort_by_cost());

	int k; cin >> k;
	vector<Table> tables;
	for (int i = 0; i < k; i++) {
		int s; cin >> s;
		tables.push_back(Table(i + 1, s));
	}
	sort(tables.begin(), tables.end(), sort_by_size());

	int total_tables = 0;
	int total_profit = 0;
	vector<pair<int, int>> pairings;

	for (auto request : requests) {
		for (int i = 0; i < tables.size(); i++) {
			if (tables[i].size >= request.people) {
				total_tables++;
				total_profit += request.cost;
				pairings.push_back(make_pair(request.id, tables[i].id));
				tables.erase(tables.begin() + i);
				break;
			}
		}
	}
	
	cout << total_tables << " " << total_profit << endl;
	for (auto pairing : pairings) {
		cout << pairing.first << " " << pairing.second << endl;
	}

}
