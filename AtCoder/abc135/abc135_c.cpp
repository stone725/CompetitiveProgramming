#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n);
    for(auto&& i : a){
        cin >> i;
    }
    for(auto&& i : b){
        cin >> i;
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(a[i], b[i]);
        b[i] -= min(a[i], b[i]);
        ans += min(a[i + 1], b[i]);
        a[i + 1] -= min(a[i + 1], b[i]);
    }
    cout << ans << "\n";
}