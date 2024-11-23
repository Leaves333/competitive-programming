#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
/*#pragma GCC target("avx2")*/

int main() {

	const int n = 1e5;
	vector<int> a(n); int s = 0;
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}

	auto start = chrono::high_resolution_clock::now();
	for (int t = 0; t < 100000; t++)
		for (int i = 0; i < n; i++)
			s += a[i];

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "here's s: " << s << endl;
	cout << "time taken: " << duration.count() << "ms" << endl;

    return 0;

}
