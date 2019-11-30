#include <iostream>

using namespace std;

int main(){
    int s[3], g[3];
    for(int i = 0; i < 3; i++){
        for(auto&& j : s){
            cin >> j;
        }
        for(auto&& j : g){
            cin >> j;
        }
        int ans[3] = {};
        for(int j = 2; j >= 0; j--){
            if(g[j] < s[j]){
                g[j - 1]--;
                g[j] += 60;
            }
            ans[j] = g[j] - s[j];
        }
        cout << ans[0] << " " <<  ans[1] << " " << ans[2] << "\n";
    }
}