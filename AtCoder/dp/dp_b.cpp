#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;

int n, k;
vector<int> h, dp;

int dfs(int now){
    if(now + 1 == n) return 0;
    if(~dp[now]) return dp[now];
    int res = INF;
    for(int i = 1; now + i < n && i <= k; i++){
        res = min(res, abs(h[now] - h[now + i]) + dfs(now + i));
    }
    return dp[now] = res;
}

int main(){
    cin >> n >> k;
    h.resize(n);
    dp.resize(n, -1);
    for(auto&& i : h){
        cin >> i;
    }
    cout << dfs(0) << "\n";
}