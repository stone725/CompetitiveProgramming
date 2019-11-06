#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    vector<int> scores, twoThrow;
    cin >> n >> m;
    scores.resize(n);
    for(auto&& i : scores){
        cin >> i;
    }
    scores.push_back(0);
    for(auto&& i : scores){
        for(auto&& j : scores){
            if(m < i + j) continue;
            twoThrow.push_back(i + j);
        }
    }
    sort(begin(twoThrow), end(twoThrow));
    int ans = 0;
    for(auto&& i : twoThrow){
        ans = max(ans, *(upper_bound(begin(twoThrow), end(twoThrow), m - i) - 1) + i);
    }
    cout << ans << "\n";
}