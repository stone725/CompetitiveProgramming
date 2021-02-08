#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    vector<pair<int, int>> judge(m), player;
    for(auto&& i : judge){
        cin >> i.first >> i.second;
    }
    int k;
    cin >> k;
    player.resize(k);
    for(auto&& i : player){
        cin >> i.first >> i.second;
    }
    int ans = 0;
    for(int i = 0; i < 1 << k; i++){
        s.clear();
        for(int j = 0; j < k; j++){
            if(i & (1 << j)){
                s.insert(player[j].first);
            }
            else{
                s.insert(player[j].second);
            }
        }
        int cnt = 0;
        for(auto&& j : judge){
            cnt += s.count(j.first) && s.count(j.second);
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}