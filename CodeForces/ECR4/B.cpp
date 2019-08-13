#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int f;
        cin >> f;
        v.push_back(make_pair(f, i));
    }
    sort(begin(v), end(v));
    long long ans = 0;
    for(int i = 1; i < n; i++){
        ans += abs(v[i].second - v[i - 1].second);
    }
    cout << ans << "\n";
}