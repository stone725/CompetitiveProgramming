#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strs(10), str2;

bool dfs(int y, int x){
    strs[y][x] = 'x';
    if(strs == vector<string>(10, string(10, 'x'))){
        return true;
    }
    static const int dy[] = {0, 1, 0, -1};
    static const int dx[] = {1, 0, -1, 0};
    for(int i = 0; i < 4; i++){
        if(y + dy[i] < 0 || y + dy[i] == 10 || x + dx[i] < 0 || x + dx[i] == 10){
            continue;
        }
        if(strs[y + dy[i]][x + dx[i]] == 'o'){
            if(dfs(y + dy[i], x + dx[i])){
                return true;
            }
        }
    }
    return false;
}

int main(){
    for(auto&& i : strs){
        cin >> i;
    }
    str2 = strs;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(strs[i][j] == 'x'){
                strs[i][j] = 'o';
                if(dfs(i, j)){
                    cout << "YES\n";
                    return 0;
                }
                strs = str2;
            }
        }
    }
    cout << "NO\n";
}