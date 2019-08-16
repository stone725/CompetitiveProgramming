#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

static const int INF = 1e9 + 7;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    c.resize(m);
    for(auto&& i : c){
        cin >> i;
    }
    sort(begin(c), end(c));
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < m; i++){
        for(int j = c[i]; j <= n; j++){
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }
    cout << dp[n] << "\n";
}