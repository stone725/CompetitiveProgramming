//未正解
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
#include <set>

using namespace std;

using ll = long long;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

vector<ll> a;
vector<vector<pair<ll, int>>> v;
vector<vector<pair<ll, int>>> v2;
vector<ll> cost;
vector<ll> cost2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    a.resize(n);
    for(auto&& i : a){
        cin >> i;
    }
    v.resize(n);
    v2.resize(n);
    cost.resize(n, 1ll << 62);
    cost2.resize(n, 1ll << 62);
    cost[0] = cost2[0] = 0;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[--a].push_back(make_pair(c, --b));
        v2[b].push_back(make_pair(c, a));
    }
    for(auto&& i : v[0]){
        pq.push(i);
    }
    while(pq.size()){
        auto info = pq.top();
        pq.pop();
        if(cost[info.second] < info.first) continue;
        cost[info.second] = info.first;
        for(auto&& i : v[info.second]){
            if(cost[i.second] < info.first + i.first) continue;
            pq.push(make_pair(info.first + i.first, i.second));
        }
    }
    for(auto&& i : v2[0]){
        pq.push(i);
    }
    while(pq.size()){
        auto info = pq.top();
        pq.pop();
        if(cost2[info.second] < info.first) continue;
        cost2[info.second] = info.first;
        for(auto&& i : v2[info.second]){
            if(cost2[i.second] < info.first + i.first) continue;
            pq.push(make_pair(info.first + i.first, i.second));
        }
    }
    long long ans = a[0] * t;
    for(int i = 1; i < n; i++){
        ans = max(ans, a[i] * (t - cost[i] - cost2[i]));
    }
    cout << ans << "\n";
}
