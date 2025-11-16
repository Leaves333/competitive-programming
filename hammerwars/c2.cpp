#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<bool>> vvb;

int main() {
    int n;
    cin>>n;
    vi nums(n);
    vi sols(n, 0);
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++){
        cin>>nums[i];
        pq.push({nums[i], i});
    }
    for(int i = 0; i < n; i++){
        while(!pq.empty() && nums[i] >= pq.top().first){
            int sec = pq.top().second;
            if(i < sec){
                sols[sec-i-1] = -1;
            }
            pq.pop();
        }
    }
    for(int i = 0; i < n; i++){
        if(sols[i] == 0){
            cout<<i + 1<<" ";
        }
    }
    cout<<"\n";
}
