#include <queue>
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

struct state {
    int x, y, type;
};

int invert_type(int type) {
    if (type == 1)
        return 0;
    else
        return 1;
}

void queue_push(int x, int y, int type, queue<state> &q, vector<vvb> &visited,
                const int n) {
    if (x < 0 || y < 0 || x >= n || y >= n)
        return;
    if (visited[x][y][type])
        return;
    visited[x][y][type] = true;
    q.push(state{x, y, type});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<vvb> visited(n, vvb(n, vb(2, false))); // x, y, move type
    queue<state> q;
    q.push({0, 0, 0});
    q.push({0, 0, 1});
    visited[0][0][0] = true;
    visited[0][0][1] = true;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        int dx, dy;
        if (cur.type) {
            dx = a;
            dy = b;
        } else {
            dx = c;
            dy = d;
        }

        int mult[4][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        for (auto m : mult) {
            queue_push(cur.x + (dx * m[0]), cur.y + (dy * m[1]),
                       invert_type(cur.type), q, visited, n);
            queue_push(cur.x + (dy * m[0]), cur.y + (dx * m[1]),
                       invert_type(cur.type), q, visited, n);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j][0] || visited[i][j][1])
                ans++;
        }
    }
    cout << ans << endl;
}
