#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7; 

int n, w;
vector<pair<int, int>> items;
int dp[100][10001];

int dfs(int no, int weight){
    if(w < weight) return -INF;
    if(no == n) return 0;
    if(~dp[no][weight]) return dp[no][weight];
    return dp[no][weight] = max(dfs(no + 1, weight), items[no].first + dfs(no + 1, weight + items[no].second));
}

int main(){
    cin >> n >> w;
    items.resize(n);
    for(auto&& i : items){
        cin >> i.first >> i.second;
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0) << "\n";
}