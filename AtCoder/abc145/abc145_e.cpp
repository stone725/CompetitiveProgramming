#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int n, t;
vector<pair<int, int>> menu;

int dp[3001][3001];

int dfs(int now, int time){
    if(now == n || t <= time){
        return 0;
    }
    if(~dp[now][time]) return dp[now][time];
    return dp[now][time] = max(dfs(now + 1, time), dfs(now + 1, time + menu[now].first) - menu[now].second);
}

int main(){
    cin >> n >> t;
    menu.resize(n);
    for(auto&& i : menu){
        cin >> i.first >> i.second;
        i.second *= -1;
    }
    sort(begin(menu), end(menu));
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0) << "\n";
}