#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;
typedef pair<int, int> pii;

int main() {
    ll n, m, k, d;
    cin>>n>>m>>k>>d;
    vector<pii> fires;
    set<pii> visited;
    ll vol = k;
    for(int i = 0; i < k; i++){
        int x, y;
        cin>>x>>y;
        fires.push_back({x-1, y-1});
        visited.insert({x-1, y-1});
    }
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    ll i = 0;
    for(; i < d; i++){
        vector<pii> temp = {};
        for(pii fire : fires){
            for(int j = 0; j < 4; j++){
                int newx = fire.first + x[j];
                int newy = fire.second + y[j];
                if((newx) < 0 || (newx) >= n){
                    continue;
                }
                if((newy) < 0 || (newy) >= m){
                    continue;
                }
                if(visited.find({newx, newy}) != visited.end()){
                    continue;
                }
                vol++;
                visited.insert({newx, newy});
                temp.push_back({newx, newy});
            }
        }
        vol += visited.size();
        fires = temp;
        if(visited.size() == m * n){
            break;
        }
        temp = {};
    }
    // cout<<i<<"\n";
    // cout<<vol<<"\n";
    // cout<<visited.size()<<"\n";
    //
    if(d > i){
        vol += (n * m) * (d - i - 1);
    }
    cout<<vol<<"\n";
}
