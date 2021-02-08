#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
vector<int> r;
int INF = 1 << 25;
int dp[3001][3002][3];

int solve(int now, int score, int upper){
    if(now == n) return 0;
    if(~dp[now][score][upper]){
        return dp[now][score][upper];
    }
    int res = solve(now + 1, score, upper);
    if(score == 3001){
        res = max(res, solve(now + 1, now, upper) + 1);
    }
    else if(upper == 0){
        if(r[score] > r[now]){
            res = max(res, solve(now + 1, now, 1) + 1);
        }
        if(r[score] < r[now]){
            res = max(res, solve(now + 1, now, 2) + 1);
        }
    }
    else if(upper == 1 && r[score] < r[now]){
        res = max(res, solve(now + 1, now, 2) + 1);
    }
    else if(upper == 2 && r[score] > r[now]){
        res = max(res, solve(now + 1, now, 1) + 1);
    }
    return dp[now][score][upper] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    r.resize(n);
    for(auto&& i : r){
        cin >> i;
    }
    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 3001, 0);
    if(ans < 3){
        ans = 0;
    }
    cout << ans << "\n";
}