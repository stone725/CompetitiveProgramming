#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int d, n;
vector<tuple<int, int, int>> items;
vector<int> days;
int dp[200][200];

int dfs(int day, int before){
    if(day == d) return 0;
    if(~dp[day][before]) return dp[day][before];
    int res = 0;
    for(int i = 0; i < n; i++){
        if(get<0>(items[i]) <= days[day] && days[day] <= get<1>(items[i])){
            if(day == 0){
                res = max(res, dfs(day + 1, i));
            }else{
                res = max(res, dfs(day + 1, i) + abs(get<2>(items[before]) - get<2>(items[i])));
            }
        }
    }
    return dp[day][before] = res;
}

int main(){
    cin >> d >> n;
    days.resize(d);
    for(auto&& i : days){
        cin >> i;
    }
    items.resize(n);
    for(auto&& i : items){
        int a, b, c;
        cin >> a >> b >> c;
        i = make_tuple(a, b, c);
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0) << "\n";
}