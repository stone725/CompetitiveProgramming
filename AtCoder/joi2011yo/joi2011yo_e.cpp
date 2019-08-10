#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

int main(){
    int h, w, n;
    static const int dx[] = {0, 1, 0, -1};
    static const int dy[] = {1, 0, -1, 0};
    cin >> h >> w >> n;
    vector<string> p(h);
    vector<pair<int, int>> point(n + 1);
    for(int i = 0; i < h; i++){
        cin >> p[i];
        for(int j = 0; j < w; j++){
            if(p[i][j] == 'S'){
                point[0] = make_pair(i, j);
            }
            if('1' <= p[i][j] && p[i][j] <= '9'){
                point[p[i][j] - '0'] = make_pair(i, j);
            }
        }
    }
    queue<tuple<int, int, int, int>> q;
    set<tuple<int, int, int>> s;
    q.push(make_tuple(point[0].first, point[0].second, 1, 0));
    while(q.size()){
        auto status = q.front();
        q.pop();
        int x = get<0>(status), y = get<1>(status), hp = get<2>(status);
        if(s.count(make_tuple(x, y, hp))){
            continue;
        }
        s.insert(make_tuple(x, y, hp));
        if(point[hp] == make_pair(x, y)){
            hp++;
            if(n < hp){
                cout << get<3>(status) << "\n";
                return 0;
            }
        }
        for(int i = 0; i < 4; i++){
            if(x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] == h || y + dy[i] == w || p[x + dx[i]][y + dy[i]] == 'X'){
                continue;
            }
            q.push(make_tuple(x + dx[i], y + dy[i], hp, 1 + get<3>(status)));
        }
    }
}