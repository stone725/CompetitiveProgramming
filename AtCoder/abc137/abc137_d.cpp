#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> job;
bool check[100001];

int main(){
    cin >> n >> m;
    job.resize(n);
    for(auto&& i : job){
        cin >> i.second >> i.first;
    }
    set<int> s;
    for(int i = 0; i <= m; i++){
        s.insert(i);
    }
    sort(rbegin(job), rend(job));
    long long ans = 0;
    for(auto&& i : job){
        if(s.lower_bound(i.second) != s.end()){
            s.erase(s.lower_bound(i.second));
            ans += i.first;
        }
    }
    cout << ans << "\n";
}