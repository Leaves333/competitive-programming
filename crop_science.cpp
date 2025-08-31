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

int main(){

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    vector<int> zero;
    int k, parent, in;
    vector<pair<int, vector<int>>> graph(3*n);
    for(int i = 0; i < m; i++){
        cin >> k >> parent;
        parent--;
        zero.push_back(parent);
        for(int j = 1; j < k; j++){
            cin >> in;
            in--;
            if(find(graph[parent].second.begin(),graph[parent].second.end(),in) == graph[parent].second.end()){
                graph[parent].second.push_back(in);
                graph[in].first++;
            }
            parent = in;
        }
    }

    queue<int> q;
    for(int i = 0; i < zero.size(); i++){
        if(graph[zero[i]].first == 0)
            q.push(zero[i]);
    }

    int total = 0;
    vector<int> sorted;
    while(!q.empty()){
        total++;
        int top = q.front();
        q.pop();
        sorted.push_back(top);
        for(int neighbor : graph[top].second){
            graph[neighbor].first--;
            if(graph[neighbor].first == 0){
                q.push(neighbor);
            }
        }
    }
    if(total != 3*n) cout << "NO";
    else{
        cout << "YES\n";
        for(int i = 0; i < 3*n; i+=3){
            cout << sorted[i]+1 << ' ' << sorted[i+1]+1 << ' ' << sorted[i+2] << '\n';
        }
    }
    
}
