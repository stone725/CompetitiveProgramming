#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    for(auto&& i : p){
        cin >> i.first >> i.second;
    }
    map<pair<long long, long long>, int> cnt;
    int ans = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            cnt[make_pair(p[i].first - p[j].first, p[i].second - p[j].second)]++;
        }
    }
    for(auto&& i : cnt){
        ans = min(ans, n - i.second);
    }
    cout << ans << "\n";
}
