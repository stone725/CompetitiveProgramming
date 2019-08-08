#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

int h, w;
vector<string> s;
vector<pair<int, int>> node[400][400];
pair<long long, long long> cnt;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y){
    if(s[x][y] == '?') return;
    if(s[x][y] == '#'){
        cnt.first++;
    }else{
        cnt.second++;
    }
    s[x][y] = '?';
    for(auto&& i : node[x][y]){
        dfs(i.first, i.second);
    } 
}

void hawawa()
{
    cin >> h >> w;
    s.resize(h);
    for (auto&& i : s) {
        cin >> i;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for(int k = 0; k < 4; k++){
                if(i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] == h || j + dy[k] == w){
                    continue;
                }
                if(s[i][j] != s[i + dx[k]][j + dy[k]]){
                    node[i][j].push_back(make_pair(i + dx[k], j + dy[k]));
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                cnt = make_pair(0, 0);
                dfs(i, j);
                ans += cnt.first * cnt.second;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    hawawa();
}
