#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    for(auto&& i : a){
        for(auto&& j : i){
            cin >> j;
            j--;
        }
    }
    vector<int> nextBattle(n);
    vector<int> day(n);
    auto c = [](tuple<int, int, int> l, tuple<int, int, int> r) { return get<2>(r) < get<2>(l); };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(c)> q(c);
    for(int i = 0; i < n; i++){
        if(i < a[i][0] && a[a[i][0]][0] == i){
            day[i] = day[a[i][0]] = 1;
            nextBattle[i] = nextBattle[a[i][0]] = 1;
            q.push(make_tuple(i, a[i][0], 1));
        }
    }
    int battlecount = 0;
    while(q.size()){
        auto status = q.top();
        q.pop();
        int x = get<0>(status);
        int y = get<1>(status);
        int d = get<2>(status);
        battlecount++;
        if(battlecount == n * (n - 1) / 2){
            cout << d << "\n";
            return 0;
        }
        if(nextBattle[x] < n - 1 && a[a[x][nextBattle[x]]][nextBattle[a[x][nextBattle[x]]]] == x){
            day[x] = day[a[x][nextBattle[x]]] = max(day[x], day[a[x][nextBattle[x]]]) + 1;
            q.push(make_tuple(x, a[x][nextBattle[x]], day[x]));
            nextBattle[a[x][nextBattle[x]]]++;
            nextBattle[x]++;
        }
        if(nextBattle[y] < n - 1 && a[a[y][nextBattle[y]]][nextBattle[a[y][nextBattle[y]]]] == y){
            day[y] = day[a[y][nextBattle[y]]] = max(day[y], day[a[y][nextBattle[y]]]) + 1;
            q.push(make_tuple(y, a[y][nextBattle[y]], day[y]));
            nextBattle[a[y][nextBattle[y]]]++;
            nextBattle[y]++;
        }
    }
    cout << -1 << "\n";
}