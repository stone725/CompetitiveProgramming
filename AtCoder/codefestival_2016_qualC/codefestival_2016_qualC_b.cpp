#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    if(t == 1){
        cout << k - 1 << "\n";
        return 0;
    }
    for(auto&& i : a){
        cin >> i;
    }
    sort(rbegin(a), rend(a));
    int ans = max(0, a[0] - (k - a[0] + 1));
    
    cout << ans << "\n";
}