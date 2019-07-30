#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, l;
    cin >> n >> m;
    vector<pair<int, int>> edge[1001];
    for(int i = 0; i < m; i++){
        int a, b, l;
        cin >> a >> b >> l;
        edge[l - 1000].push_back(make_pair(a, b));
        edge[l - 1000].push_back(make_pair(b, a));
    }
    for(auto&& i : edge){
        sort(begin(i), end(i));
    }
    int ans = 0;
    for(int i = 0; i <= 1000; i++){    
        if(2540 < i + 2000) break;
        for(auto&& j : edge[i]){
            for(auto it = lower_bound(begin(edge[2540 - i - 2000]), end(edge[2540 - i - 2000]), make_pair(j.second, 0)); it != end(edge[2540 - i - 2000]) && it->first == j.second; it++){
                ans += j.first < it->second;
            }
        }
    }
    cout << ans << "\n";
}