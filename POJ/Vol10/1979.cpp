#include <iostream>
#include <vector>
#include <string>

using namespace std;

int w, h;
vector<string> tiles;

static const int dx[] = {0, 1, 0, -1};
static const int dy[] = {1, 0, -1, 0};

int dfs(int x, int y){
    tiles[x][y] = '#';
    int res = 1;
    for(int i = 0; i < 4; i++){
        if(tiles[x + dx[i]][y + dy[i]] == '.'){
            res += dfs(x + dx[i], y + dy[i]);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> w >> h && w && h){
        tiles.resize(h + 2, string(w + 2, '#'));
        int px = 0, py = 0;
        for(int i = 1; i <= h; i++){
            string str;
            cin >> str;
            tiles[i] = "#" + str + "#";
            if(px) continue;
            for(int j = 1; j <= w; j++){
                if(tiles[i][j] == '@'){
                    px = i;
                    py = j;
                    break;
                }
            }
        }
        cout << dfs(px, py) << "\n";
        tiles.clear();
    }
}