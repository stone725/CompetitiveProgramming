#include <iostream>
#include <queue>
#include <set>
#include <utility>

using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double maxScore = -1;
    int ans1, ans2;
    queue<pair<int, int>> q;
    set<pair<int, int>> s;
    q.push(make_pair(a, 0));
    q.push(make_pair(b, 0));
    while(q.size()){
        auto status = q.front();
        q.pop();
        if(f < 100 * status.first + status.second){
            continue;
        }
        if(s.count(status)){
            continue;
        }
        s.insert(status);
        if(maxScore < 100. * status.second / (100 * status.first + status.second)){
            maxScore = 100. * status.second / (100 * status.first + status.second);
            ans1 = 100 * status.first + status.second;
            ans2 = status.second;
        }
        q.push(make_pair(status.first + a, status.second));
        q.push(make_pair(status.first + b, status.second));
        if(status.second + c <= status.first * e){
            q.push(make_pair(status.first, status.second + c));
        }
        if(status.second + d <= status.first * e){
            q.push(make_pair(status.first, status.second + d));
        }
    }
    cout << ans1 << " " << ans2 << "\n";
}
