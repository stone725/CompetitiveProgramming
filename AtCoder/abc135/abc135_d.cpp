#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int INF = 1e9 + 7;
short mod = 13;
string str;
long long dp[100000][13];

long long dfs(int now, int m){
    if(now == str.size()) return m == 5;
    if(~dp[now][m]) return dp[now][m];
    long long res = 0;
    if(str[now] == '?'){
        for(int i = 0; i < 10; i++){
            res += dfs(now + 1, (m * 10 + i) % mod);
            res %= INF;
        }
    }else{
        res = dfs(now + 1, (m * 10 + str[now] - '0') % mod);
        res %= INF;
    }
    return dp[now][m] = res;
}

int main(){
    cin >> str;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << "\n";
}