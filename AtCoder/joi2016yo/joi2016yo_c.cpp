#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static const int INF = 1e9 + 7;
int n, m;
vector<string> flag;

int cnt(string s, const char&& c){
    return upper_bound(begin(s), end(s), c) - lower_bound(begin(s), end(s), c);
}

int dfs(int now, char c){
    if(now == n - 1){
        if(c == 'W') return INF;
        return 0;
    }
    if(c == 'W'){
        return min(dfs(now + 1, 'W') + m - cnt(flag[now], 'W'), dfs(now + 1, 'B') + m - cnt(flag[now], 'B'));
    }else if(c == 'B'){
        return min(dfs(now + 1, 'B') + m - cnt(flag[now], 'B'), dfs(now + 1, 'R') + m - cnt(flag[now], 'R'));
    }else{
        return dfs(now + 1, 'R') + m - cnt(flag[now], 'R');
    }
}

int main(){
    cin >> n >> m;
    flag.resize(n);
    for(auto&& i : flag){
        cin >> i;
        sort(begin(i), end(i));
    }
    int ans = 2 * m - cnt(flag[0], 'W') - cnt(flag[n - 1], 'R');
    ans += dfs(1, 'W');
    cout << ans << "\n";
}