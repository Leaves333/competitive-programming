#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream fout("test.txt");
    fout << "500000 1 250000\n";

    for (int i = 0; i < 250000; i++) {
        fout << 1 << " " << i + 1 << "\n";
    }
}
