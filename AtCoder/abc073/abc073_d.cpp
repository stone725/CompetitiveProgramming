#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

static const int INF = 1e9 + 7;

int n, m, r;
vector<int> check;
vector<vector<int>> cost;
int dp[1 << 8][201];

int dfs(int bit, int now){
    if(bit == ((1 << r) - 1)){
        return 0;
    }
    if(~dp[bit][now]) return dp[bit][now];
    int res = INF;
    for(int i = 0; i < r; i++){
        if((1 << i) & bit){
            continue;
        }
        res = min(res, dfs(bit ^ (1 << i), i) + cost[check[now]][check[i]]);
    }
    return dp[bit][now] = res;
}

int main(){
    cin >> n >> m >> r;
    check.resize(r);
    for(auto&& i : check){
        cin >> i;
        i--;
    }
    cost.resize(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        cost[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a - 1][b - 1] = cost[b - 1][a - 1] = c;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = INF;
    for(int i = 0; i < r; i++){
        ans = min(ans, dfs(1 << i, i));
    }
    cout << ans << "\n";
}