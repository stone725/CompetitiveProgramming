#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int d, g;
vector<pair<int, int>> p;
vector<vector<int>> dp;

int dfs(int now, int score){
    if(now == d){
        if(g <= score){
            return 0;
        }else{
            return 1 << 25;
        }
    }
    if(g <= score) return 0;
    if(~dp[now][score]) return dp[now][score];
    int res = 1 << 25;
    for(int i = 0; i <= p[now].first; i++){
        res = min(res, i + dfs(now + 1, score + i * (now + 1) * 100 + (i == p[now].first) * p[now].second));
    }
    return dp[now][score] = res;
}

int main(){
    cin >> d >> g;
    dp.resize(d, vector<int>(g, -1));
    p.resize(d);
    for(auto&& i : p){
        cin >> i.first >> i.second;
    }

    cout << dfs(0, 0) << "\n";
}