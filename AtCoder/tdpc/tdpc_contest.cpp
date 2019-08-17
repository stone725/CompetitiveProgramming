#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto&& i : p){
        cin >> i;
    }
    bool dp[101][10001] = {};
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 10000; j++){
            if(j < p[i]) dp[i + 1][j] = dp[i][j];
            else dp[i + 1][j] = dp[i][j] || dp[i][j - p[i]];
        }
    }
    int ans = 0;
    for(int i = 0; i <= 10000; i++){
        ans += dp[n][i];
    }
    cout << ans << "\n";
}