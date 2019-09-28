#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m && n && m){
        int ans = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            ans += min(a, m / n);
        }
        cout << ans << "\n"; 
    }
}