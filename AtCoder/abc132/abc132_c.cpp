#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(auto&& i : d){
        cin >> i;
    }
    sort(begin(d), end(d));
    cout << d[n / 2] - d[n / 2 - 1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}