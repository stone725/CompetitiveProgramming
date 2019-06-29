#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto&& i : p){
        cin >> i;
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(p[i - 1] <= p[i] && p[i] <= p[i + 1]) ans++;
        else if(p[i + 1] <= p[i] && p[i] <= p[i - 1]) ans++;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}