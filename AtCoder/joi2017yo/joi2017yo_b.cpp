#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(auto&& i : a){
        int b;
        cin >> i >> b;
    }
    sort(rbegin(a), rend(a));
    int ans = 0;
    for(int i = 0; i < m - 1; i++){
        ans += max(0, n - a[i]);
    }
    cout << ans << "\n";
}