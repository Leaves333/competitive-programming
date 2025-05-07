#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

const ll MOD = 1000000007;
const int N = 100;
struct matrix {
    ll arr[N][N];
};

matrix multiply_matrices(const matrix &first, const matrix &second) {
    matrix res;
    memset(res.arr, 0, sizeof(res.arr));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll sum = 0;
            for (int k = 0; k < N; k++) {
                sum += first.arr[i][k] * second.arr[k][j];
                sum %= MOD;
            }
            res.arr[i][j] = sum;
        }
    }
    return res;
}

matrix pow_mod(matrix base, ll exp) {

    matrix res;
    memset(res.arr, 0, sizeof(res.arr));
    for (int i = 0; i < N; i++) {
        res.arr[i][i] = 1;
    }

    while (exp > 0) {
        if (exp & 1) {
            res = multiply_matrices(res, base);
        }
        base = multiply_matrices(base, base);
        exp >>= 1;
    }

    return res;

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    matrix pow_matrix;
    memset(pow_matrix.arr, 0, sizeof(pow_matrix.arr));
    pow_matrix.arr[0][0] = 1;
    pow_matrix.arr[0][m-1] = 1;
    for (int i = 0; i < N - 1; i++) {
        pow_matrix.arr[i+1][i] = 1;
    }

    matrix base_matrix;
    memset(base_matrix.arr, 0, sizeof(base_matrix.arr));
    base_matrix.arr[N - 1][0] = 1;
    for (int i = N - 2; i >= 0; i--) {
        base_matrix.arr[i][0] = base_matrix.arr[i+1][0];
        if (i + m < N)
            base_matrix.arr[i][0] += base_matrix.arr[i+m][0];
        base_matrix.arr[i][0] %= MOD;
    }

    if (n < N) {
        cout << base_matrix.arr[N - 1 - n][0] << endl;
        return 0;
    }

    matrix ans = pow_mod(pow_matrix, n - N + 1);
    ans = multiply_matrices(ans, base_matrix);
    cout << ans.arr[0][0] << endl;

}
